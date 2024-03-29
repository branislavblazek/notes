﻿#!/usr/bin/env python3
# Copyright (c) 2008-9 Qtrac Ltd. All rights reserved.
# This program or module is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version. It is provided for educational
# purposes and is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.

import bisect
import contextlib
import copy
import gzip
import os
import pickle
import random
import socketserver
import struct
import sys
import threading


class Car:

    def __init__(self, seats, mileage, owner):
        self.__seats = seats
        self.mileage = mileage
        self.owner = owner


    @property
    def seats(self):
        return self.__seats


    @property
    def mileage(self):
        return self.__mileage


    @mileage.setter
    def mileage(self, mileage):
        self.__mileage = mileage


    @property
    def owner(self):
        return self.__owner


    @owner.setter
    def owner(self, owner):
        self.__owner = owner



class Finish(Exception): pass


class RequestHandler(socketserver.StreamRequestHandler):

    CarsLock = threading.Lock()
    CallLock = threading.Lock()
    Call = dict(
            GET_CAR_DETAILS=(
                    lambda self, *args: self.get_car_details(*args)),
            GET_LICENSES_STARTING_WITH=(
                    lambda self, *args:
                            self.get_licenses_starting_with(*args)),
            CHANGE_MILEAGE=(
                    lambda self, *args: self.change_mileage(*args)),
            CHANGE_OWNER=(
                    lambda self, *args: self.change_owner(*args)),
            NEW_REGISTRATION=(
                    lambda self, *args: self.new_registration(*args)),
            SHUTDOWN=lambda self, *args: self.shutdown(*args))


    def handle(self):
        InfoVersion = 1
        InfoStruct = struct.Struct("!IB")
        info = self.rfile.read(InfoStruct.size)
        size, version = InfoStruct.unpack(info)
        if version > InfoVersion:
            reply = (False, "klient je nekompatibilní")
        else:
            data = pickle.loads(self.rfile.read(size))
            try:
                with self.CallLock:
                    function = self.Call[data[0]]
                reply = function(self, *data[1:])
            except Finish:
                return
        data = pickle.dumps(reply, 3)
        self.wfile.write(InfoStruct.pack(len(data), InfoVersion))
        self.wfile.write(data)


    def get_car_details(self, license):
        with self.CarsLock:
            car = copy.copy(self.Cars.get(license, None))
        if car is not None:
            return (True, car.seats, car.mileage, car.owner)
        return (False, "Tato SPZ není registrována")
        

    def get_licenses_starting_with(self, start):
        with self.CarsLock:
            keys = list(self.Cars.keys())
        keys.sort()
        right = left = bisect.bisect_left(keys, start)
        while right < len(keys) and keys[right].startswith(start):
            right += 1
        return (True, keys[left:right])


    def change_mileage(self, license, mileage):
        if mileage < 0:
            return (False, "Nemohu nastavit záporný počet km")
        with self.CarsLock:
            car = self.Cars.get(license, None)
            if car is not None:
                if car.mileage < mileage:
                    car.mileage = mileage
                    return (True, None)
                return (False, "Nemohu přetočit tachometr zpět")
        return (False, "Tato SPZ není registrována")
        

    def change_owner(self, license, owner):
        if not owner:
            return (False, "Nemohu nastavit prázdného vlastníka")
        with self.CarsLock:
            car = self.Cars.get(license, None)
            if car is not None:
                car.owner = owner
                return (True, None)
        return (False, "Tato SPZ není registrována")
        

    def new_registration(self, license, seats, mileage, owner):
        if not license:
            return (False, "Nemohu nastavit prázdnou SPZ")
        if seats not in {2, 4, 5, 6, 7, 8, 9}:
            return (False, "Nemohu zaregistrovat vůz s neplatným počtem sedadel")
        if mileage < 0:
            return (False, "Nemohu nastavit záporný počet km")
        if not owner:
            return (False, "Nemohu nastavit nevyplněného vlastníka")
        with self.CarsLock:
            if license not in self.Cars:
                self.Cars[license] = Car(seats, mileage, owner)
                return (True, None)
        return (False, "Nemohu zaregistrovat duplicitní SPZ")
        

    def shutdown(self, *ignore):
        self.server.shutdown()
        raise Finish()
        

class CarRegistrationServer(socketserver.ThreadingMixIn,
                            socketserver.TCPServer): pass


def save(filename, cars):
    try:
        with contextlib.closing(gzip.open(filename, "wb")) as fh:
            pickle.dump(cars, fh, 3)
    except (EnvironmentError, pickle.UnpicklingError) as err:
        print("uložení dat na serveru se nezdařilo: {0}".format(err))
        sys.exit(1)


def load(filename):
    if not os.path.exists(filename):
        # Vygeneruj smyšlená data
        cars = {}
        owners = []
        for forename, surname in zip(("Warisha", "Elysha", "Liona",
                "Kassandra", "Simone", "Halima", "Liona", "Zack",
                "Josiah", "Sam", "Braedon", "Eleni"),
                ("Chandler", "Drennan", "Stead", "Doole", "Reneau",
                 "Dent", "Sheckles", "Dent", "Reddihough", "Dodwell",
                 "Conner", "Abson")):
            owners.append(forename + " " + surname)
        for license in ("1H1890C", "FHV449", "ABK3035", "215 MZN",
                "6DQX521", "174-WWA", "999991", "DA 4020", "303 LNM",
                "BEQ 0549", "1A US923", "A37 4791", "393 TUT", "458 ARW",
                "024 HYR", "SKM 648", "1253 QA", "4EB S80", "BYC 6654",
                "SRK-423", "3DB 09J", "3C-5772F", "PYJ 996", "768-VHN",
                "262 2636", "WYZ-94L", "326-PKF", "EJB-3105", "XXN-5911",
                "HVP 283", "EKW 6345", "069 DSM", "GZB-6052", "HGD-498",
                "833-132", "1XG 831", "831-THB", "HMR-299", "A04 4HE",
                "ERG 827", "XVT-2416", "306-XXL", "530-NBE", "2-4JHJ"):
            mileage = random.randint(0, 100000)
            seats = random.choice((2, 4, 5, 6, 7))
            owner = random.choice(owners)
            cars[license] = Car(seats, mileage, owner)
        return cars
        #return {}
    try:
        with contextlib.closing(gzip.open(filename, "rb")) as fh:
            return pickle.load(fh)
    except (EnvironmentError, pickle.UnpicklingError) as err:
        print("server nemůže načíst data: {0}".format(err))
        sys.exit(1)


def main():
    filename = os.path.join(os.path.dirname(__file__),
                            "car_registrations.dat")
    cars = load(filename)
    print("Načteno {0} registrací vozů".format(len(cars)))
    RequestHandler.Cars = cars
    server = None
    try:
        server = CarRegistrationServer(("", 9653), RequestHandler)
        server.serve_forever()
    except Exception as err:
        print("CHYBA", err)
    finally:
        if server is not None:
            server.shutdown()
            save(filename, cars)
            print("Uloženo {0} registací vozů".format(len(cars)))


main()

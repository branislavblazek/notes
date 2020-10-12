class IncidentError: pass

class Incident:
    def __init__(self, report_id, date, airport, aircraft_id, aircraft_type, pilot_percent_hours_on_type, pilot_total_hours, midair, narrative=""):
        assert len(report_id) >= 8 and len(report_id.split()) == 1, "Neplatne ID hlasenia."

        self.__report_id = report_id
        self.date = date
        self.airport = airport
        self.aircraft_id = aircraft_id
        self.aircraft_type = aircraft_type
        self.pilot_percent_hours_on_type = pilot_percent_hours_on_type
        self.pilot_total_hours = pilot_total_hours
        self.midair = midair
        self.narrative = narrative

    @property
    def date(self):
        return self.__date

    @date.setter
    def date(self, date):
        assert(isinstance(date, datetime.date)), "Neplatny datum."
        self.__date = date

    @property
    def pilot_percent_hours_on_type(self)
        return self.__pilot_percent_hours_on_type

    @pilot_percent_hours_on_type.setter
    def pilot_percent_hours_on_type(self, percent):
        assert 0.0 <= percent <= 100.0, "procentní podíl mimo rozsah"
        self.__pilot_percent_hours_on_type = percent

    @property
    def pilot_total_hours(self):
        return self.__pilot_total_hours

    @pilot_total_hours.setter
    def pilot_total_hours(self, hours):
        assert hours > 0, "neplatný počet hodin"
        self.__pilot_total_hours = hours

    @property
    def approximate_hours_on_type(self):
        return int(self.__pilot_total_hours * (self.__pilot_percent_hours_on_type / 100))

    @property
    def midair(self):
        return self.__midair

    @midair.setter
    def midair(self, value):
        assert isinstance(value, bool), "neplatná hodnota vlastnosti midair"
        self.__midair = value


    @property
    def airport(self):
        "Letiště nehody"
        return self.__airport

    @airport.setter
    def airport(self, airport):
        assert airport and "\n" not in airport, "neplatné letiště"
        self.__airport = airport

    @property
    def aircraft_id(self):
        "ID letadla"
        return self.__aircraft_id

    @aircraft_id.setter
    def aircraft_id(self, aircraft_id):
        assert aircraft_id and "\n" not in aircraft_id, "neplatné ID letadla"
        self.__aircraft_id = aircraft_id

    @property
    def aircraft_type(self):
        return self.__aircraft_type

    @aircraft_type.setter
    def aircraft_type(self, aircraft_type):
        assert aircraft_type and "\n" not in aircraft_type, \
               "neplatný typ letadla"
        self.__aircraft_type = aircraft_type

    @property
    def narrative(self):
        "popis nehody"
        return self.__narrative

    @narrative.setter
    def narrative(self, narrative):
        self.__narrative = narrative
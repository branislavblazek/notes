import collections
import math
import sys

Statistics = collections.namedtuple('Statistics', 'mean mode median std_dev')

def main():
    if len(sys.argv) == 1 or sys.argv[1] in {'-h', '--help'}:
        print('pouzitie: {} subor1'.format(sys.argv[0]))
        sys.exit()

    numbers = []
    frequencies = collections.defaultdict(int)
    for filename in sys.argv[1:]:
        read_data(filename, numbers, frequencies)
    if numbers:
        statistics = calculate_statistics(numbers, frequencies)
        print_result(len(numbers), statistics)
    else:
        print('neboli najdene ziadne cisla')

def read_data(filename, numbers, frequencies):
    for lino, line in enumerate(open(filename), start=1):
        for x in line.split():
            try:
                number = float(x)
                numbers.append(number)
                frequencies[number] += 1
            except ValueError as err:
                print('[filename]:[lino}: skipping {x]: {err}'.format(**locals()))

def calculate_statistics(numbers, frequencies):
    mean = sum(numbers) / len(numbers)#priemer
    mode = calculate_mode(frequencies, 3)
    median = calculate_median(numbers)
    std_dev = calculate_std_dev(numbers, mean)
    
    return Statistics(mean, mode, median, std_dev)

def calculate_mode(frequencies, maximum_modes):
    highest_frequency = max(frequencies.values())
    mode = [number for number, frequency in frequencies.items() if frequency == highest_frequency]
    if not (1 <= len(mode) <= maximum_modes):
        mode = None
    else:
        mode.sort()
    return mode

def calculate_median(numbers):
    numbers = sorted(numbers)
    middle = len(numbers) // 2
    median = numbers[middle]
    if len(numbers) % 2 == 0:
        median = (median + numbers[middle - 1]) / 2

    return median

def calculate_std_dev(numbers, mean):
    total = 0
    for number in numbers:
        total += ((number - mean) **2)
    variance = total / (len(numbers) - 1)
    return math.sqrt(variance)

def print_result(count, statistics):
    real = '9.2f'

    if statistics.mode is None:
        modeline = ''
    elif len(statistics.mode) == 1:
        modeline = 'modus = {0:{fmt}}\n'.format(statistics.mode[0], fmt=real)
    else:
        modeline = ("modus = [" + ", ".join(["{0:.2f}".format(m) for m in statistcs.mode]) + "]\n")

    print("""\
pocet       = {0:6}
stred       = {mean:{fmt}}
median      = {median:{fmt}}
{1}\
sm. odch    = {std_dev:{fmt}}""".format(count, modeline, fmt=real, **statistics._asdict()))   


main()

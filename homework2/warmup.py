"""Thomas O'Brien/Tyler Edmiston Homework #2 Python"""

import re
import random
import math
from itertools import zip_longest
import requests
from Crypto.Cipher import AES


def change(cents):
    '''
    A function that accepts a number of U.S. cents and returns a tuple
    containing, respectively, the smallest number of U.S. quarters, dimes,
    nickels, and pennies that equal the given amount.
    '''
    if cents < 0:
        raise ValueError('amount cannot be negative')
    total_change = []
    for coin_value in [25, 10, 5, 1]:
        number_of_coins, cents = divmod(cents, coin_value)
        total_change.append(number_of_coins)
    return tuple(total_change)


def strip_quotes(string):
    '''
    A function that accepts a string and returns a new string equivalent to
    the argument but with all apostrophes and double quotes removed.
    '''
    return re.sub('[\'\"]', '', string)


def scramble(string):
    '''
    A function that randomly permutes a string. What does random mean? It
    means that each time you call the function for a given argument, all
    possible permutations are equally likely. Random is not the same as
    arbitrary.
    '''
    return ''.join(random.sample(string, len(string)))


def say(word=None):
    '''
    A chainable function that accepts one string per call, but when called
    without arguments, returns the words previously passed, in order,
    separated by a single space.
    '''
    def inner(next_word=None):
        '''
        Either returns the final string or passes the next instance
        of the string.
        '''
        if next_word is None:
            return word
        return say('{} {}'.format(word, next_word))
    return '' if word is None else inner


def triples(max_hypotenuse):
    '''
    Returns a list of all (positive) integer Pythagorean triples for all
    hypotenuse values up to, and including, some value.
    '''
    if max_hypotenuse < 0:
        raise ValueError('amount cannot be negative')
    triple_list = []
    for side_c in range(1, max_hypotenuse + 1):
        for side_b in range(1, side_c):
            for side_a in range(1, side_b):
                if side_a * side_a + side_b * side_b == side_c * side_c:
                    triple_list.append((side_a, side_b, side_c))
    triple_list.sort()
    return triple_list


def powers(base, max_number):
    '''
    A generator function that yields successive powers of a base starting at
    1 and going up to some limit.
    '''
    value = 1
    while value <= max_number:
        yield value
        value *= base


def interleave(array1, *array2):
    '''
    A function that interleaves an array with a bunch of values. If the array
    length is not the same as the number of values to interleave, the extra
    elements should end up at the end of the result.
    '''
    longest = zip_longest(array1, array2)
    return [item for tuples in longest for item in tuples if item is not None]


class Cylinder:
    "A cylinder class with a radius, height, and several methods"
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height

    @property
    def volume(self):
        "Returns the volume of the cylinder object"
        return math.pi * self.radius * self.radius * self.height

    @property
    def surface_area(self):
        "Returns the surface area of the cylinder object"
        return math.pi * self.radius * self.height * 2 + (
            2 * math.pi * self.radius * self.radius)

    def widen(self, value):
        "Adjusts the radius of a cylinder object"
        self.radius *= value

    def stretch(self, value):
        "Adjusts the height of a cylinder object"
        self.height *= value

    def __repr__(self):
        return 'Cylinder with radius {} and height {}'.format(
            self.radius, self.height)


def make_crypto_functions(crypto_key, initial_vector):
    '''
    A function that accepts two arguments: a crypto key and an
    initialization_vector (IV), and returns a tuple of two functions.
    The first function encrypts a bytes object with the simple AES algorithm
    using CBC (using the key and IV). The second decrypts. Both functions
    accept a bytes object and return a bytes object. Use the pycrypto package.
    '''
    new_crypto_key = crypto_key
    new_initial_vector = initial_vector

    def encrypt(encrypt_bytes):
        "Encrypts a bytes object"
        cipher = AES.new(new_crypto_key, AES.MODE_CBC, new_initial_vector)
        return cipher.encrypt(encrypt_bytes)

    def decrypt(decrypt_bytes):
        "Decrypts a bytes object"
        cipher = AES.new(new_crypto_key, AES.MODE_CBC, new_initial_vector)
        return cipher.decrypt(decrypt_bytes)

    return (encrypt, decrypt)


def random_name(**data):
    '''
    A function that returns a random name from the uinames API. This function
    should use the requests module and you are to fetch the data synchronously
    (SORRY!) Pass the URL query parameters as kwargs.
    '''
    payload = {'gender': data['gender'], 'region': data['region'], 'amount': 1}
    uninames = requests.get('http://uinames.com/api/', params=payload)
    if not uninames.ok:
        raise ValueError(uninames.text)
    person = uninames.json()
    return '{}, {}'.format(person['surname'], person['name'])

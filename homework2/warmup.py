import requests
import re
import random
import math
from Crypto.Cipher import AES


def change(cents):
    if cents < 0:
        raise ValueError('amount cannot be negative')
    change = []
    for coin in [25, 10, 5, 1]:
        coins, cents = divmod(cents, coin)
        change.append(coins)
    return tuple(change)


def strip_quotes(string):
    return re.sub('[\'\"]', '', string)


def scramble(string):
    return ''.join(random.sample(string, len(string)))


def say(word=None):
    def inner(next_word=None):
        if next_word is None:
            return word
        return say('{} {}'.format(word, next_word))
    return '' if word is None else inner


def triples(max_hypotenuse):
    if max_hypotenuse < 0:
        raise ValueError('amount cannot be negative')
    triple_list = []
    for c in range(1, max_hypotenuse + 1):
        for b in range(1, c):
            for a in range(1, b):
                if a * a + b * b == c * c:
                    triple_list.append((a, b, c))
    triple_list.sort()
    return triple_list


def powers(base, max):
    value = 1
    while value <= max:
        yield value
        value *= base


def interleave(array1, *array2):
    array1Clone = list(array1)
    indexInArray2 = 0
    for i in range(0, min(len(array1), len(array2))):
        array1Clone.insert(indexInArray2 * 2 + 1, array2[indexInArray2])
        indexInArray2 += 1
    return array1Clone + list(array2[indexInArray2:len(array2)])


class Cylinder():
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height
        self.volume = self.calculate_volume()
        self.surface_area = self.calculate_surface_area()

    def widen(self, value):
        self.radius *= value

    def stretch(self, value):
        self.height *= value

    def calculate_volume(self):
        return math.pi * self.radius * self.radius * self.height

    def calculate_surface_area(self):
        return math.pi * self.radius * self.height * 2 + (
            2 * math.pi * self.radius * self.radius)

    def __repr__(self):
        return 'Cylinder with radius {} and height {}'.format(
            self.radius, self.height)


def make_crypto_functions(crypto_key, initial_vector):
    new_crypto_key = crypto_key
    new_initial_vector = initial_vector

    def encrypt(encrypt_bytes):
        cipher = AES.new(new_crypto_key, AES.MODE_CBC, new_initial_vector)
        return cipher.encrypt(encrypt_bytes)

    def decrypt(decrypt_bytes):
        cipher = AES.new(new_crypto_key, AES.MODE_CBC, new_initial_vector)
        return cipher.decrypt(decrypt_bytes)

    return (encrypt, decrypt)


def random_name(**data):
    payload = {'gender': data['gender'], 'region': data['region'], 'amount': 1}
    person = requests.get('http://uinames.com/api/', params=payload)
    if 'error' in person.json():
        raise ValueError(person.text)
    else:
        return '{}, {}'.format(person.json()['surname'], person.json()['name'])


# if __name__ == '__main__':
#     c = Cylinder(height=10, radius=2)
#     # print('c.radius: {}'.format(c.radius))
#     # print('c.height: {}'.format(c.height))
#     test = c.volume
#     print('c.volume(): {}'.format(test))
#     print('c.volume()\'s type: {}'.format(type(c.volume())))

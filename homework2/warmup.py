import requests
import re
import random
from Crypto.Cipher import AES


def change(cents):
    if cents < 0:
        raise ValueError('amount cannot be negative')
    quarters = cents // 25
    maxQuarters = quarters * 25
    dimes = (cents - maxQuarters) // 10
    nickels = (cents - maxQuarters - dimes * 10) // 5
    return (quarters, dimes, nickels, cents % 5)


def strip_quotes(string):
    return re.sub('[\'\"]', '', string)


def scramble(string):
    result = []
    stringArray = list(string)
    while len(stringArray) > 0:
        randIndex = random.randint(0, len(stringArray) - 1)
        result.append(stringArray[randIndex])
        stringArray.pop(randIndex)
    return ''.join(result)


def say(word=None):
    def inner(nextWord=None):
        if nextWord is None:
            return word
        return say('{} {}'.format(word, nextWord))
    return '' if word is None else inner


def triples(maxHypotenuse):
    if maxHypotenuse < 0:
        raise ValueError('amount cannot be negative')
    tripleList = []
    for c in range(1, maxHypotenuse + 1):
        for b in range(1, c):
            for a in range(1, b):
                if a * a + b * b == c * c:
                    tripleList.append((a, b, c))
    tripleList.sort()
    return tripleList


def powers(base, max):
    value = 1
    while value <= max:
        yield value
        value *= base


def interleave():
    return False


def Cylinder():
    return False


def make_crypto_functions(cryptoKey, intialVector):
    newCryptoKey = cryptoKey
    newintialVector = intialVector

    def encrypt(encryptByte):
        return 'encrypt'

    def decrypt(decryptByte):
        return 'decrypt'
    return (encrypt, decrypt)


def random_name(**data):
    payload = {'gender': data['gender'], 'region': data['region'], 'amount': 1}
    person = requests.get('http://uinames.com/api/', params=payload)
    if 'error' in person.json():
        raise ValueError(person.text)
    else:
        return '{}, {}'.format(person.json()['surname'], person.json()['name'])

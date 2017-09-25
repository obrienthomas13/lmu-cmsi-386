import requests, re
# import pycrypto
#        ^ Needs to be something like 'from Crypto.xxxx import xxxx'


def change(cents):
    if cents < 0 :
        raise ValueError("amount cannot be negative");
    quarters = (cents // 25);
    dimes = ((cents - (quarters * 25)) // 10);
    nickels = ((cents - (quarters * 25) - (dimes * 10)) // 5);

    return (quarters, dimes, nickels, cents % 5);


def strip_quotes(str):
    return re.sub('[\'\"]', '', str)


def scramble():
    return False


def say():
    return False


def triples():
    return False


def powers():
    return False


def interleave():
    return False


def Cylinder():
    return False


def make_crypto_functions():
    return False


def random_name(**data):
    payload = {'gender': data['gender'], 'region': data['region'], 'amount': 1}
    person = requests.get('http://uinames.com/api/', params=payload).json()
    return '{}, {}'.format(person['surname'], person['name'])
    # return '{}, {}'.format(person.json()['surname'], person.json()['name']) if person.ok else raise ValueError('{}'.format(person.json()))

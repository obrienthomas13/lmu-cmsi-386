const crypto = require('crypto');
const rp = require('request-promise');

exports.change = function change(cents) {
  if (cents < 0) {
    throw new RangeError('amount cannot be negative');
  }
  const quarters = Math.floor(cents / 25);
  const dimes = Math.floor((cents - (quarters * 25)) / 10);
  const nickels = Math.floor((cents - (quarters * 25) - (dimes * 10)) / 5);
  return [quarters, dimes, nickels, cents % 5];
};

exports.stripQuotes = function stripQuotes(str) {
  return str.replace(/['"]+/g, '');
};

// no temp
exports.scramble = function scramble(str) {
  const result = [];
  const strArray = str.split('');
  while (strArray.length > 0) {
    const rand = Math.floor(Math.random() * (strArray.length));
    result.push(strArray[rand]);
    strArray.splice(rand, 1);
  }
  return result.join('');
};

exports.powers = function powers(base, max, callback) {
  let value = 0;
  while (value + value <= max && max > 0) {
    if (value === 0) {
      value = 1;
    } else {
      value += value;
    }
    callback(value);
  }
};

exports.powersGenerator = function* powersGenerator(base, max) {
  let value = 1;
  while ((value) <= max) {
    yield value;
    value *= base;
  }
};

exports.say = function say(word) {
  return (!word) ? '' : (nextWord) => {
    if (!nextWord) {
      return word;
    }
    return say(`${word} ${nextWord}`);
  };
};

exports.interleave = function interleave(array1, ...array2) {
  const initLength = array1.length;
  for (let i = 1; i <= initLength; i += 2) {
    if (array2.length === 0) { break; }
    array1.splice(i, 0, array2.shift(0));
  }
  return array1.concat(array2);
};

exports.cylinder = function cylinder(data) {
  let radius = data.radius || 1;
  let height = data.height || 1;

  function widen(value) {
    radius *= value;
  }
  function stretch(value) {
    height *= value;
  }
  function volume() {
    return Math.PI * radius * radius * height;
  }
  function surfaceArea() {
    return (Math.PI * radius * height * 2) + (2 * Math.PI * radius * radius);
  }
  function toString() {
    return `Cylinder with radius ${radius} and height ${height}`;
  }
  return Object.freeze({
    get height() {
      return height;
    },
    get radius() {
      return radius;
    },
    widen,
    stretch,
    volume,
    surfaceArea,
    toString,
  });
};

exports.makeCryptoFunctions = function makeCryptoFunctions(key, alg) {
  const localKey = key;
  const localAlg = alg;
  return [
    function encrypt(str) {
      const cipher = crypto.createCipher(localAlg, localKey);
      let crypted = cipher.update(str, 'utf8', 'hex');
      crypted += cipher.final('hex');
      return crypted;
    },
    function decrypt(str) {
      const decipher = crypto.createDecipher(localAlg, localKey);
      let dec = decipher.update(str, 'hex', 'utf8');
      dec += decipher.final('utf8');
      return dec;
    },
  ];
};

exports.randomName = function randomName(data) {
  const options = {
    uri: `http://uinames.com/api/?gender=${data.gender}&region=${data.region}&amount=1`,
    json: true,
  };
  function printPerson(person) {
    return `${person.surname}, ${person.name}`;
  }
  return rp(options).then(printPerson);
};

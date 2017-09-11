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

exports.scramble = function scramble(str) {
  const result = [];
  const strTemp = str.split('');
  while (strTemp.length > 0) {
    const rand = Math.floor(Math.random() * (strTemp.length));
    result.push(strTemp[rand]);
    strTemp.splice(rand, 1);
  }
  return result.join('');
};

exports.powers = function powers(base, max) {
  let value = 1;
  while (value < max) {
    value *= base;
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
  if (!word) {
    return this;
  }
  return word + this.say();
};

exports.interleave = function interleave(array1, ...array2) {
  const initLength = array1.length;
  for (let i = 1; i <= initLength; i += 2) {
    if (array2.length === 0) { break; }
    array1.splice(i, 0, array2[0]);
    array2.shift();
  }
  return array1.concat(array2);
};

exports.cylinder = function cylinder(data) {
  let radius = data.radius || 1;
  let height = data.height || 1;

  // Note: Widen and stretch do work in the sense that the area changes when you
  // call these functions, but when you get radius/heaight it doesnt. Think the
  // getters are broken
  function widen(value) {
    // console.log(radius + " before");
    radius *= value;
    // console.log(radius + " after");
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

  function getRadius() {
    // console.log(radius + " radius")
    return radius;
  }
  function getHeight() {
    return height;
  }

  return Object.freeze({
    radius,
    height,
    getRadius,
    getHeight,
    widen,
    stretch,
    volume,
    surfaceArea,
  });

  // return false;
};

exports.makeCryptoFunctions = function makeCryptoFunctions() {
  return false;
};

exports.randomName = function randomName() {
  return false;
};

module.export = {

};

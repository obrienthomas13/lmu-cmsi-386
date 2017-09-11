function change(cents) {
  if (cents < 0) {
    throw new RangeError('amount cannot be negative');
  }
  const quarters = Math.floor(cents / 25);
  const dimes = Math.floor((cents - (quarters * 25)) / 10);
  const nickels = Math.floor((cents - (quarters * 25) - (dimes * 10)) / 5);
  return [quarters, dimes, nickels, cents % 5];
}

function stripQuotes(str) {
  return str.replace(/['"]+/g, '');
}

function scramble(str) {
  const result = [];
  const strTemp = str.split('');
  while (strTemp.length > 0) {
    const rand = Math.floor(Math.random() * (strTemp.length));
    result.push(strTemp[rand]);
    strTemp.splice(rand, 1);
  }
  return result.join('');
}

function powers(base, max, other) {
  let value = 1;
  while (value < max) {
    value *= base;
  }
}

function* powersGenerator(base, max) {
  let value = 1;
  while ((value) <= max) {
    yield value;
    value *= base;
  }
}

function say(word) {
  if (!word) {
    return this;
  }
  return word + this.say();
}

function interleave(array1, ...array2) {
  const initLength = array1.length;
  for (let i = 1; i <= initLength; i += 2) {
    if (array2.length === 0) { break; }
    array1.splice(i, 0, array2[0]);
    array2.shift();
  }
  return array1.concat(array2);
}

function cylinder(data) {
  let radius = data.radius || 1;
  let height = data.height || 1;

  // Note: Widen and stretch do work in the sense that the area changes when you
  // call these functions, but when you get radius/heaight it doesnt. Think the
  // getters are broken
  function widen(value) {
    console.log(radius + " before");
    radius *= value;
    console.log(radius + " after");
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
    console.log(radius + " radius")
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
    surfaceArea
  });

  return false;
}

function makeCryptoFunctions() {
  return false;
}

function randomName() {
  return false;
}

module.export = {
  change,
  stripQuotes,
  scramble,
  powers,
  powersGenerator,
  say,
  interleave,
  cylinder,
  makeCryptoFunctions,
  randomName,
};

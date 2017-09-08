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

exports.powers = function powers() {
  return false;
};

exports.powersGenerator = function powersGenerator() {
  return false;
};

exports.say = function say() {
  return false;
};

exports.interleave = function interleave() {
  return false;
};

exports.cylinder = function cylinder() {
  return false;
};

exports.makeCryptoFunctions = function makeCryptoFunctions() {
  return false;
};

exports.randomName = function randomName() {
  return false;
};

// console.log(change(3));
// console.log(stripQuotes('aer""""er4"potato'))

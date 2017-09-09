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

exports.powers = function powers(base, max, other) {
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

module.export = {

};

let help = this.powersGenerator(2, 1);
console.log(help.next());
console.log(help.next());
console.log(help.next());
console.log(help.next());
console.log(help.next());
console.log(help.next());

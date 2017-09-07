function change (cents) {
  const quarters = Math.floor(cents / 25);
  const dimes = Math.floor((cents - (quarters * 25)) / 10);
  const nickels = Math.floor((cents - (quarters * 25) - (dimes * 20)) / 5);
  return [quarters, dimes, nickels, cents % 5];
}

function stripQuotes (str) {
  return str.replace(/['"]+/g, '');
}

function scramble () {
  return false;
}

function powers () {
  return false;
}

function powersGenerator (base, exp) {
  return false;
}

function say () {
  return false;
}

function interleave () {
  return false;
}

function cylinder () {
  return false;
}

function makeCryptoFunctions () {
  return false;
}

function randomName () {
  return false;
}

console.log(change(3));
console.log(stripQuotes('aer""""\'er4"potato'))

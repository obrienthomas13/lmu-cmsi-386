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

// exports.say = const say = ((word) => {
exports.say = function say(word) {
  // function nextString(totalStr) {
  //   let next = totalStr.concat(' ');
  //   return next;
  // }
  // function endString() {
  //
  // }
  console.log("are you happening");
  let chainedString = '';
  return () => {
    if (word !== undefined) {
      chainedString += word;
      // return chainedString;
    }
    return chainedString;
    // return chainedString.slice(0, chainedString.length - 1);
  };

  // ===============================================================
  // let [last, current] = ['', word];
  // return () => {
  //   let memory = Array.prototype.slice.call( word );
  //   return function() {
  //     let local = memory.slice();
  //     Array.prototype.push.apply( local, word );
  //   };
    // if (last === '') {
    //   // console.log('condition one');
    //   // console.log('before');
    //   // console.log('last: ' + last);
    //   // console.log('current: ' + current);
    //   [last, current] = [current, ''];
    //   // console.log('after');
    //   // console.log('last: ' + last);
    //   // console.log('current: ' + current);
    //   return last;
    // } else if (word !== undefined) {
    // // if (word !== undefined) {
    //   console.log('condition two');
    //   last = current;
    //   current = current.concat(' ').concat(word);
    //   // let result = chain === undefined ? chain : chain.concat(word).concat(' ');
    //   console.log('last: ' + last);
    //   console.log('current: ' + current);
    //   return [last, current];
    // }
    // console.log('condition three');
    // console.log(last);
    // // return last.slice(0, last.length - 1);
    // return last;
    // ===============================================================
  // };
  // return (chain) => {
  //   if (word !== undefined) {
  //     // let result = chain === undefined ? chain : chain.concat(word).concat(' ');
  //     // console.log(result);
  //     return chain === undefined ? word : chain.concat(word).concat(' ');
  //   }
  //   console.log('second');
  //   return chain.slice(0, chain.length - 1);
  // };
};

exports.interleave = function interleave(array1, ...array2) {
  const initLength = array1.length;
  for (let i = 1; i <= initLength; i += 2) {
    if (array2.length === 0) { break; }
    array1.splice(i, 0, array2.shift(0));
  }
  return array1.concat(array2);
};

exports.cylinder = function cylinder({radius = 1, height = 1}) {
  // Note: Widen and stretch do work in the sense that the area changes when you
  // call these functions, but when you get radius/heaight it doesnt. Think the
  // getters are broken
  let widen = (value) => {
    radius *= value;
  }
  let stretch = (value) => {
    height *= value;
  }
  let volume = () => {
    return Math.PI * radius * radius * height;
  }
  let surfaceArea = () => {
    return (Math.PI * radius * height * 2) + (2 * Math.PI * radius * radius);
  }

  // function getRadius() {
  //   return radius;
  // }
  // function getHeight() {
  //   return height;
  // }
  let toString = () => {
    return `Cylinder with radius ${radius} and height ${height}`;
  }

  return Object.freeze({
    radius,
    height,
    // getRadius,
    // getHeight,
    widen,
    stretch,
    volume,
    surfaceArea,
    toString,
  });

  // return false;
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
  return rp(options)
    .then((repos) => {
      return `${repos.surname}, ${repos.name}`;
    });
  // return rp(options)
  //   .then( function rp(repos) {
  //     return `${repos.surname}, ${repos.name}`;
  //   });
};

module.export = {

};

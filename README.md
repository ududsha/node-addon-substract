# node-addon-substract
Node addon example : Substract 2 numbers

Your JS file should look like: 

var addon = require('bindings')('addon.node');
console.log('Your answer is:', addon.substract(6,3))

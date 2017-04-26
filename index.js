var ictclas = require('bindings')('ictclas.node');

module.exports = () => {
    ictclas.init();
    return ictclas;
}();

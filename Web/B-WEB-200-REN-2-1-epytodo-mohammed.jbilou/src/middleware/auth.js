const jwt = require('jsonwebtoken');
const { get_secret } = require('../config/helper');

const is_jwt_valid = (req) => {
    if (req.headers == undefined)
        return false;
    const token = req.headers.authorization;
    if (!token) {
        return false;
    }
    try {
        const decoded = jwt.verify(token, get_secret());
        return true;
    } catch (error) {
        console.error('Invalid Token:', error);
        return false;
    }
};

module.exports = {
    is_jwt_valid,
}
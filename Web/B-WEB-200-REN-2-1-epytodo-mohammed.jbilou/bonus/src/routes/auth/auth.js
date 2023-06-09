const jwt = require('jsonwebtoken');

const get_pool = require("../../config/db.js");
const { gen_rand_str, get_secret, gen_hash } = require("../../config/helper.js");

const login = (email, password) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                reject(err);
                return;
            }
            const sql = 'select * from user where email = ? and password = ?';
            gen_hash(password).then((hash) => {
                let values = [email, hash];
                connection.query(sql, values, (error, results) => {
                    if (error) {
                        reject(error);
                    }
                    if (results.length > 0) {
                        connection.release();
                        const token = jwt.sign(gen_rand_str(10), get_secret());
                        resolve(token);
                    } else {
                        connection.release();
                        resolve(undefined);
                    }
                });
            });
        });
    });
};

module.exports = {
    login,
};
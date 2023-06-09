const jwt = require('jsonwebtoken');

const get_pool = require("../../config/db.js");
const { gen_rand_str, get_secret, gen_hash } = require("../../config/helper.js");

const query_register = (email, password, name, firstname) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'INSERT INTO user (name, firstname, email, password) VALUES (?, ?, ?, ?)';
            gen_hash(password).then((hash) => {
                let values = [name, firstname, email, hash];
                connection.query(sql, values, (error, results) => {
                    if (error) {
                        if (error.code === 'ER_DUP_ENTRY') {
                            resolve(undefined);
                        } else {
                            reject(error);
                        }
                        return;
                    }
                    connection.release();
                    const jwtToken = jwt.sign(gen_rand_str(10), get_secret());
                    resolve(jwtToken);
                });
            });
        });
    });
};

const query_get_user_all = () => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'select * from user';
            connection.query(sql, [], (error, results) => {
                if (error) {
                    reject(error);
                }
                connection.release();
                resolve(results);
            });
        });
    });
};

const query_get_user_id = (id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'select * from user where id = ?';
            connection.query(sql, [id], (error, results) => {
                if (error) {
                    reject(error);
                }
                connection.release();
                resolve(results);
            });
        });
    });
};

const query_get_user_email = (email) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'select * from user where email = ?';
            connection.query(sql, [email], (error, results) => {
                if (error) {
                    reject(error);
                }
                connection.release();
                resolve(results);
            });
        });
    });
};

const query_delete_user_id = (id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'delete from user where id = ?';
            connection.query(sql, [id], (error, results) => {
                if (error) {
                    reject(error);
                }
                connection.release();
                if (results.affectedRows > 0)
                    resolve(true);
                else
                    resolve(false);
            });
        });
    });
};

const query_update_user_id = (email, password, name, firstname, id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'UPDATE user SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?';
            gen_hash(password).then((hash) => {
                let values = [email, hash, name, firstname, id];
                connection.query(sql, values, (error, results) => {
                    if (error) {
                        if (error.code === 'ER_DUP_ENTRY') {
                            resolve(false);
                        } else {
                            reject(error);
                        }
                    }
                    connection.release();
                    resolve(true);
                });
            });
        });
    });
}

module.exports = {
    query_register,
    query_get_user_all,
    query_get_user_id,
    query_get_user_email,
    query_delete_user_id,
    query_update_user_id,
};
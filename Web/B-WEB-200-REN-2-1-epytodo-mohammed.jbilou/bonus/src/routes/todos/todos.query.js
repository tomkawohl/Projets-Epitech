const jwt = require('jsonwebtoken');

const get_pool = require("../../config/db.js");

const query_get_todo_all = () => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'select * from todo';
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

const query_get_todo_id = (id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'select * from todo where id = ?';
            connection.query(sql, [id], (error, results) => {
                if (error) {
                    reject(error);
                }
                connection.release();
                if (results.length == 0)
                    resolve({ status: false, arr: [] });
                else
                    resolve({ status: true, arr: results });
            });
        });
    });
};

const query_create_todo = (title, description, due_time, user_id, status) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'insert todo (title, description, due_time, user_id, status) values (?, ?, ?, ?, ?)';
            connection.query(sql, [title, description, due_time, user_id, status], (error, results) => {
                if (error) {
                    if (error.code == "ER_NO_REFERENCED_ROW_2")
                        resolve("FK_ERR");
                    reject(error);
                }
                pool.getConnection((err, connection) => {
                    if (err) {
                        console.log(err);
                        reject(err);
                        return;
                    }
                    const sql = 'select * from todo where title = ? and description = ? and due_time = ? and user_id = ? and status = ?';
                    connection.query(sql, [title, description, due_time, user_id, status], (error, results) => {
                        if (error) {
                            reject(error);
                        }
                        resolve(results[0]);
                        connection.release();

                    });
                });
            });
        });
    });
};

const query_edit_todo = (title, description, due_time, user_id, status, id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'update todo set title = ?, description = ?, due_time = ?,   user_id = ?, status = ? where id = ?';
            connection.query(sql, [title, description, due_time, user_id, status, id], (error, results) => {
                if (error) {
                    console.log(error);
                    if (error.code == "ER_NO_REFERENCED_ROW_2")
                        resolve("FK_ERR");
                    if (error.code == "ER_DUP_ENTRY")
                        resolve("DUP");
                    reject(error);
                }
                console.log(results);
                if (results.affectedRows == 0)
                    resolve("NO_ID");
                pool.getConnection((err, connection) => {
                    if (err) {
                        console.log(err);
                        reject(err);
                        return;
                    }
                    const sql = 'select * from todo where title = ? and description = ? and due_time = ? and user_id = ? and status = ? and id = ?';
                    connection.query(sql, [title, description, due_time, user_id, status, id], (error, results) => {
                        if (error) {
                            reject(error);
                        }
                        resolve(results[0]);
                        connection.release();

                    });
                });
            });
        });
    });
};

const query_delete_todo_id = (id) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const sql = 'delete from todo where id = ?';
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

const query_get_task_by_due_time = (due_time) => {
    return new Promise((resolve, reject) => {
        const pool = get_pool();
        pool.getConnection((err, connection) => {
            if (err) {
                console.log(err);
                reject(err);
                return;
            }
            const query = "SELECT * FROM todo WHERE due_time > ?";
            connection.query(query, [due_time], (error, results) => {
                if (error) {
                    reject(error);
                } else {
                    resolve(results);
                }
            });
        });
    });
};

module.exports = {
    query_get_todo_all,
    query_get_todo_id,
    query_create_todo,
    query_edit_todo,
    query_delete_todo_id,
    query_get_task_by_due_time
};
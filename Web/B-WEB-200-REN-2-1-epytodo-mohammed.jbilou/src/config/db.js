require('dotenv').config();
const mysql = require('mysql2');

const db_database = process.env.MYSQL_DATABASE;
const db_host = process.env.MYSQL_HOST;
const db_user = process.env.MYSQL_USER;
const db_password = process.env.MYSQL_ROOT_PASSWORD;


const get_pool = () => {
    const pool = mysql.createPool({
        host: db_host,
        user: db_user,
        password: db_password,
        database: db_database,
    });
    return pool;
}

module.exports = get_pool;
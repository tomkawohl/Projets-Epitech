const express = require("express");
const app = express();
const jwt = require('jsonwebtoken');

const { is_jwt_valid } = require("../../middleware/auth.js");

const user_query = require("./user.query.js");
const { is_password_secure } = require("../../config/helper.js");

const register = (req, res) => {
    if (req.body == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (!('email' in req.body) || !('password' in req.body) ||
        !('name' in req.body) || !('firstname' in req.body)) {
        res.send(JSON.stringify({ "msg ": "Bad parameter" }));
        return;
    }
    const { email, password, name, firstname } = req.body;
    if (!is_password_secure(password)) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    user_query.query_register(email, password, name, firstname).then(token => {
        if (token == undefined)
            res.send(JSON.stringify({ msg: "Account already exists" }));
        else
            res.send(JSON.stringify({ token: token }));
    }).catch(error => {
        console.log(error);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const get_user_all = (req, res) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    user_query.query_get_user_all().then((arr) => {
        res.send(JSON.stringify(arr));
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const get_user_id = (req, res, id) => {
    if (id == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    user_query.query_get_user_id(id).then((arr) => {
        if (arr.length == 0)
            res.send(JSON.stringify({ "msg": "Bad parameter" }));
        else
            res.send(JSON.stringify(arr[0]));
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const get_user_email = (req, res, email) => {
    if (email == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    user_query.query_get_user_email(email).then((arr) => {
        if (arr.length == 0)
            res.send(JSON.stringify({ "msg": "Bad parameter" }));
        else
            res.send(JSON.stringify(arr[0]));
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const update_user_id = (req, res, id) => {
    if (req.body == undefined || id == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (!('email' in req.body) || !('password' in req.body) ||
        !('name' in req.body) || !('firstname' in req.body)) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    const { email, password, name, firstname } = req.body;

    user_query.query_update_user_id(email, password, name, firstname, id).then(token => {
        if (token == false)
            res.send(JSON.stringify({ "msg": "Bad parameter" }));
        else {
            user_query.query_get_user_id(id).then((arr) => {
                if (arr.length == 0)
                    res.send(JSON.stringify({ "msg": "Bad parameter" }));
                else
                    res.send(JSON.stringify(arr[0]));
            });
        }
    }).catch(error => {
        console.log(error);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const delete_user_id = (req, res, id) => {
    if (id == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    user_query.query_delete_user_id(id).then((results) => {
        if (results == false)
            res.send(JSON.stringify({ "msg": "Bad parameter" }));
        else
            res.send(JSON.stringify({ "msg": "Successfully deleted record number: " + id }));
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

module.exports = {
    register,
    get_user_all,
    get_user_id,
    get_user_email,
    delete_user_id,
    update_user_id,
};
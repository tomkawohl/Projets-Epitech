const express = require("express");
const app = express();
const jwt = require('jsonwebtoken');

const { is_jwt_valid } = require("../../middleware/auth.js");

const todo_query = require("./todos.query.js");

const get_todo_all = (req, res) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    todo_query.query_get_todo_all().then((arr) => {
        res.send(JSON.stringify(arr));
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const get_todo_id = (req, res) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    todo_query.query_get_todo_id().then((ret) => {
        if (ret.status == true)
            res.send(JSON.stringify(ret.arr[0]));
        else {
            res.send(JSON.stringify({ "msg": "Bad parameter" }));
            console.log(res);
        }
    }).catch(err => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error" }));
    });
}

const create_todo = (req, res) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    const { title, description, due_time, user_id, status } = req.body;
    if (title == undefined || description == undefined || due_time == undefined ||
        user_id == undefined || status == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    todo_query.query_create_todo(title, description, due_time, user_id, status).
        then((ret) => {
            if (ret == "FK_ERR") {
                res.send(JSON.stringify({ "msg": "Bad parameter" }));
                return;
            }
            res.send(JSON.stringify(ret));
        }).catch((err) => {
            console.log(err);
            res.send(JSON.stringify({ msg: "error" }));
        });
}

const edit_todo = (req, res, id) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    const { title, description, due_time, user_id, status } = req.body;
    if (title == undefined || description == undefined || due_time == undefined ||
        user_id == undefined || status == undefined || id == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    todo_query.query_edit_todo(title, description, due_time, user_id, status, id).
        then((ret) => {
            if (ret == "FK_ERR" || ret == "NO_ID" || ret == "DUP") {
                res.send(JSON.stringify({ "msg": "Bad parameter" }));
                return;
            }
            res.send(JSON.stringify(ret));
        }).catch((err) => {
            console.log(err);
            res.send(JSON.stringify({ msg: "error" }));
        });
}

const delete_todo_id = (req, res, id) => {
    if (id == undefined) {
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
        return;
    }
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid" }));
        return;
    }
    todo_query.query_delete_todo_id(id).then((results) => {
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
    get_todo_all,
    get_todo_id,
    create_todo,
    edit_todo,
    delete_todo_id
};
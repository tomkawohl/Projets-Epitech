const dotenv = require("dotenv").config(".env");
const express = require("express");
const path = require("path");
const app = express();
const bodyParser = require('body-parser');
const port = process.env.port;
const date = new Date();


const user = require("./routes/user/user.js");
const auth = require("./routes/auth/auth.js");
const todo = require("./routes/todos/todos.js");
const { is_jwt_valid } = require("./middleware/auth.js");

const { is_num } = require("./config/helper.js");

const get_due_time = require("./bonus/get_task.js");

/*
const get_due_time = () => {
    get_todo_by_due_time();
}
*/

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.post("/task_due_time", (req, res) => {
    if (req.body == undefined) {
        res.send(JSON.stringify({ "msg ": "Bad parameter" }));
        return;
    }
    get_due_time.get_task_by_due_time(req, res);
});

app.post("/register", (req, res) => {
    user.register(req, res);
});

app.post("/login", (req, res) => {
    if (req.body == undefined) {
        res.send(JSON.stringify({ "msg ": "Bad parameter" }));
        return;
    }
    if (!("email" in req.body) || !("password" in req.body)) {
        res.send(JSON.stringify({ "msg ": "Bad parameter" }));
        return;
    }
    const { email, password } = req.body;
    auth.login(email, password).then(token => {
        if (token == undefined)
            res.send(JSON.stringify({ msg: "Not found" }));
        else
            res.send(JSON.stringify({ token: token }));
    }).catch(error => {
        res.send(JSON.stringify({ msg: "error" }));
    });
});

app.get("/user", (req, res) => {
    user.get_user_all(req, res);
});

app.get("/user/todo", (req, res) => {
    todo.get_todo_all(req, res);
});

app.get("/user/:input", (req, res) => {
    if (is_num(req.params.input))
        user.get_user_id(req, res, req.params.input);
    else if(is_email(req.params.input))
        user.get_user_email(req, res, req.params.input);
    else
        res.send(JSON.stringify({ "msg": "Bad parameter" }));
});

app.delete("/user/:id", (req, res) => {
    user.delete_user_id(req, res, req.params.id);
});

app.put("/user/:id", (req, res) => {
    user.update_user_id(req, res, req.params.id);
});

app.get("/todos", (req, res) => {
    todo.get_todo_all(req, res);
});

app.get("/todos/:id", (req, res) => {
    todo.get_todo_id(req, res, req.params.id);
});

app.post("/todos", (req, res) => {
    todo.create_todo(req, res);
});

app.put("/todos/:id", (req, res) => {
    todo.edit_todo(req, res, req.params.id);
});

app.delete("/todos/:id", (req, res) => {
    todo.delete_todo_id(req, res, req.params.id);
});

app.listen(port, () => {
    console.log(`Example app listening at http:localhost:${port}`);
});

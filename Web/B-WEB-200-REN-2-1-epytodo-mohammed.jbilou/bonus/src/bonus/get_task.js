const { is_jwt_valid } = require("../middleware/auth.js");
const todo_query = require("../routes/todos/todos.query.js");

const get_task_by_due_time = (req, res) => {
    if (is_jwt_valid(req) == false) {
        res.send(JSON.stringify({ "msg": "Token is not valid"}));
        return;
    }
    const { due_time } = req.body;
    if (due_time == undefined) {
        res.send(JSON.stringify({"msg": "Bad parameter"}));
    return;
    }
todo_query.query_get_task_by_due_time(due_time)
    .then((arr) => {
        res.send(JSON.stringify(arr));
    })
    .catch((err) => {
        console.log(err);
        res.send(JSON.stringify({ msg: "error"}));
    });
};

module.exports = {
    get_task_by_due_time
};
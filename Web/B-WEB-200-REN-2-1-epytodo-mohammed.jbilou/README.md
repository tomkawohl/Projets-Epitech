# EPYTODO

Synopsis : The project idea is to build a Todo List.

How to use it (using Postman) : 

|  Done |      Route         | Method | Protected |           Description               |
|-------|--------------------|--------|-----------|-------------------------------------|
|   ✅  |   /register        |  POST  |    no     |     Register a new user             |
|   ✅  |    /login          |  POST  |    no     |      Connect a user                 |
|   ✅  |     /user          |  GET   |    yes    |   View all user information         |
|   ✅  |  /user/todos       |  GET   |    yes    |     View all user tasks             |
|   ✅  | /users/:id or:email|  GET   |    yes    |    View user information            |
|   ✅  |    /users/:id      |  PUT   |    yes    |    Update user information          |
|   ✅  |    /users/:id      | DELETE |    yes    |          Delete user                |
|   ✅  |     /todos         |  GET   |    yes    |      View all the todos             |
|   ✅  |   /todos/:id       |  GET   |    yes    |        View the todo                |
|   ✅  |     /todos         |  POST  |    yes    |        Create a todo                |
|   ✅  |   /todos/:id       |  PUT   |    yes    |        Update a todo                |
|   ✅  |   /todos/:id       | DELETE |    yes    |        Delete a todo                |


Bonus:
|  Done |      Route         | Method | Protected |           Description               |
|-------|--------------------|--------|-----------|-------------------------------------|
|   ✅  | /task_due_time     |  POST  |    yes    | get task that are < to the date renseigner |
    exemple of body JSON in postman :
        {
            "due_time":"2023-05-22 21:00:00"
        }

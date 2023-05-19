This project is a command line executable to mimic ordering Zapiekanka from one of three different stores. <br/> 
The possible stores are: <br/> 
      Plac Nowy Zapiekanka: it has two possible Zapiekanka you can order: <br/> 
            Cheese      - thick crust dough, marinara sauce, gouda cheese <br/> 
            Custom      - thick crust dough, plum tomato sauce, oscypek cheese  <br/> 
                              and the possiblity to choose either olives, mushrooms  <br/> 
                              or both as toppings <br/> 
      Plac Wolnicy Zapiekanka: it has two possible Zapiekanka you can order: <br/> 
            Zakopane    - thin crust dough, plum tomato sauce, oscypek cheese, boczek and olives <br/> 
            Custom      - thin crust dough, marinara sauce, gouda cheese  <br/> 
                              and the possiblity to choose either olives, boczek  <br/> 
                              or both as toppings <br/> 
      Zapiekankatopia: it allows you to build your own zapiekanka from scratch, choosing <br/> 
            dough:      thin or thick <br/> 
            sauce:      marinara or plum tomato <br/> 
            cheese:     oscypek, gouda or mozzarella <br/> 
            toppings:   mushrooms, olives, boczek, salami <br/> 
 <br/> 
The program will guide you through every step of the order ;)  <br/> 
             <br/> 
================================================================================================ <br/> 
 <br/> 
COMPILE: <br/> 
Compiling from inside the main directory (you need gtest to compile): <br/> 
      mkdir bin <br/> 
      cmake -S . -B bin/ <br/> 
       <br/> 
After compiling you will have two executables <br/> 
      Zapiekanka:       the main program <br/> 
      ZapiekankaTest:   the gTest 

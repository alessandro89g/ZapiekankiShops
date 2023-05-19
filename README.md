This project is a command line executable to mimic ordering Zapiekanka from one of three different stores.\ 
The possible stores are:\ 
      Plac Nowy Zapiekanka: it has two possible Zapiekanka you can order: 
            Cheese      - thick crust dough, marinara sauce, gouda cheese 
            Custom      - thick crust dough, plum tomato sauce, oscypek cheese  
                              and the possiblity to choose either olives, mushrooms  
                              or both as toppings 
      Plac Wolnicy Zapiekanka: it has two possible Zapiekanka you can order: 
            Zakopane    - thin crust dough, plum tomato sauce, oscypek cheese, boczek and olives 
            Custom      - thin crust dough, marinara sauce, gouda cheese  
                              and the possiblity to choose either olives, boczek  
                              or both as toppings 
      Zapiekankatopia: it allows you to build your own zapiekanka from scratch, choosing 
            dough:      thin or thick 
            sauce:      marinara or plum tomato 
            cheese:     oscypek, gouda or mozzarella 
            toppings:   mushrooms, olives, boczek, salami 
 
The program will guide you through every step of the order ;)  
             
================================================================================================ 
 
COMPILE: 
Compiling from inside the main directory (you need gtest to compile): 
      mkdir bin 
      cmake -S . -B bin/ 
       
After compiling you will have two executables 
      Zapiekanka:       the main program 
      ZapiekankaTest:   the gTest 

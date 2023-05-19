This project is a command line executable to mimic ordering Zapiekanka from one of three different stores. <br/> 
The possible stores are: <br/> 
&nbsp;&ensp;Plac Nowy Zapiekanka: it has two possible Zapiekanka you can order: <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;Cheese&nbsp;&ensp;- thick crust dough, marinara sauce, gouda cheese <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;Custom&nbsp;&ensp;- thick crust dough, plum tomato sauce, oscypek cheese&ensp;<br/> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&ensp;and the possiblity to choose either olives, mushrooms&ensp;<br/> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&ensp;or both as toppings <br/> 
&nbsp;&ensp;Plac Wolnicy Zapiekanka: it has two possible Zapiekanka you can order: <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;Zakopane&nbsp;- thin crust dough, plum tomato sauce, oscypek cheese, boczek and olives <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;Custom&nbsp;&ensp;- thin crust dough, marinara sauce, gouda cheese&ensp;<br/> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&ensp;and the possiblity to choose either olives, boczek&ensp;<br/> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&ensp;or both as toppings <br/> 
&nbsp;&ensp;Zapiekankatopia: it allows you to build your own zapiekanka from scratch, choosing <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;dough:&nbsp;&ensp;thin or thick <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;sauce:&nbsp;&ensp;marinara or plum tomato <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;cheese:&nbsp; oscypek, gouda or mozzarella <br/> 
&nbsp;&nbsp;&nbsp;&nbsp;toppings:&ensp; mushrooms, olives, boczek, salami <br/> 
 <br/> 
The program will guide you through every step of the order ;)&ensp;<br/> 
&nbsp;&nbsp;&nbsp;&nbsp; <br/> 
====================================================================================== <br/> 
 <br/> 
COMPILE: <br/> 
Compiling from inside the main directory (you need gtest to compile): <br/> 
&nbsp;&ensp;mkdir bin <br/> 
&nbsp;&ensp;cmake -S . -B bin/ <br/> 
&nbsp;&ensp; <br/> 
After compiling you will have two executables <br/> 
&nbsp;&ensp;Zapiekanka:&nbsp;&ensp; the main program <br/> 
&nbsp;&ensp;ZapiekankaTest:&ensp; the gTest 

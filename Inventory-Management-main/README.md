# Stockify: An Inventory Management Tool

<h3>Introduction:</h3>

---

Stockify is an inventory management tool designed to managing inventory levels and automating operations. This system reads data from an external file called "database.txt". The file contains information about each product, such as the product name, price per unit, quantity, supplier name, supplier’s division, shelf location, number of days stored, and demand level. The system consists of three complex logics which are performed using the input data. The tool uses for loops, if statements, and nested loops to process and analyze data. It also uses topics like structure, nested structure, array, string, string array and some other void functions for decoration.

a.	The first logic identifies products with low demand ( <4 ) that have been stored for a long time ( >3 months ) in warehouses. This feature helps to avoid overstocking and products becoming expired.

b.	The logic displays the location of products in the different divisions of the country and lists sellers from each division. This helps to identify from where the products are camming the most and which divisions are performing the best.

c.	The third logic generates bills to order high demand ( >6 ) and low stock products ( <50 ) based on user input. This ensures that there is always enough inventory to meet customer demand and minimizing excess inventory.

Overall, Stockify optimizes inventory management. That can save time, reduce costs, and improve performance.



 
<h3>Methodology</h3>

***

<h5>Function 1: listOfOverStock( );</h5>

Console:

![logic 1](https://github.com/kausaraahmed/Inventory-Management/assets/111121885/5de3413f-712b-4835-ac55-4ff63d9135b0)


The listOfOverStock() function filters out products that have been stored in the warehouse for more than 90 days and have a demand score of 3 or less. Then this function presents a list of overstocked items, including the product name, shelf location, and the number of days the item has been stored.
To execute this, the function uses a for loop that iterates through the data from 0 to 29. Within the loop, using an if statement, the function compares the product[i].dayStored and product[i].demand properties of each product. If both conditions are true (i.e., the product has been stored for more than 90 days and has a demand score of 3 or less), the function prints the product name, shelf location, and the number of days it has been in storage.
 


<h5>Function 2: productArea( );</h5>

Console:

![logic 2](https://github.com/kausaraahmed/Inventory-Management/assets/111121885/5b410836-be56-4a44-ab19-70e27046974f)


The productArea() function is used to list the product suppliers from each division and provide statistics on the distinct divisions and their products.
To perform this, the function executes two nested for loops that iterate through all the data. It uses the
product[i].sup.division property and compares it with a sample division array of strings using an if statement. If the division matches, the function prints the supplier's name under the corresponding division name. And it stores the number of times the division name appears in a separate array.
The productArea() function then generates statistics on the distinct divisions and their products based on the array. 


 
<h5>Function 3: productRestock( );</h5>

Console:

![logic 3](https://github.com/kausaraahmed/Inventory-Management/assets/111121885/254158ea-b65c-4b4b-9714-d5d052d77474)


The productRestock() function identifies products that need to be restocked and calculates the quantity of each product that needs to be ordered. The function first lists products with demand score of 7 or greater and products less than 50 units left in stock.
After displaying the list of products, the function prompts the user to enter the number of units needed to restock those products. The function then calculates the number of units to order for each product based on the input. For instance, if user enter order size 95 and there are 50 units of Rice in inventory, then this logic will order (95 – 50) = 45 unit of Rice. After this It prepares a bill for the total restocking cost. But there is a minimum order limit. If the user enters an amount less than the limit, an error message is displayed.
The productRestock() function uses a for loop to iterate through all the data from 0 to 29. Within the loop, it compares the product[i].quantity and product[i].demand properties of each product using an if statement. If a product has less than 50 units left and a demand score of 7 or greater, the function includes it in the list of products that need to be restocked.
For each product in the list, the function displays the product name, the quantity of units to order, the per unit price, the subtotal, and the grand total. The function uses a price variable to store the subtotal for each product and a total variable to store the grand total.



<h3>Conclusion:</h3>

---

Stockify is an efficient inventory management tool that automates complex inventory management operations. Its functionality is based on three complex logics that involve data from an external file. 
The listOfOverStock() function, filters out overstocked items based on the product's storage time and demand score. The productArea() function, lists the product suppliers from each division and provides statistics on the distinct divisions and their products. The productRestock() function, identifies products that need to be restocked and prepares a bill for the total restocking cost. The tool applies for loops, if statements, and nested loops to process  
and analyze data. By using structure, nested structure, array, string, string array and some other void functions to decorate and make the tool more engaging. This system can also be customized to fit the specific needs of any other inventory queries.
Overall, Stockify is a tool that can optimize inventory management and improve performance by minimizing excess inventory, reducing costs, and saving time.

# REST_API_Tester

List of content

- [Intro](#Intro)
- [Description](#Description)
    - [Basic_Functionality](#Basic_Functionality)
    	- [GET_Example](#GET_Example)
    - [Tests](#Tests)
        - [Tests_Example](#Tests_Example)
    
# Intro

Project for university course C++

Created in C++/QML is a desktop app that can be used to test
simple REST functionality such as GET, POST, PUT, DELETE.

**Authors:**
- [Rafał Szczepanik](https://github.com/rafalsz98)
- [Paweł Tomczyk](https://github.com/pawelinformatyk)
- [Krystian Turek](https://github.com/krystian886)
- [Mateusz Sass](https://github.com/Matiisen)

App was written and tested using Qt Creator 4.14 based on Qt 5.15.2

![qt-version](/readme_files/qt-v.png)


# Description

As app starts, it shows us its Results tab - so far empty.
That is the place where detailed answer from the backend source will be put.

![start](/readme_files/app-start.png)


## Basic_Functionality

This app is mainly focused on showing REST answers from the server
with the help of its four built in queries:
		- GET
		- POST
		- DELETE
		- PUT
		
![queries](/readme_files/queries.png)

### GET_Example

Using the app is fairly easy as it is shown below:

where to put the desired IP

![ip](/readme_files/ip.png)

where to add more properties

![props](/readme_files/props.png)

simple example

![get-example](/readme_files/get-example.png)

now PRESS **GREEN BUTTON**...

... and the app shows us the response in Results tab

![get-example-response](/readme_files/get-example-response.png)

**!!!ATTENTION!!!** if IP is not providen by the user, app uses its default option
which is	https://www.google.com


## Tests

However not always detailed answer is necessary.
Sometimes when testing lots of queries, user may decide to check them 
simultaneously and the only needed response is the **Status Code**.

In such scenario the **Unit Tests** tab is the perfect choice.

![unit-tests](/readme_files/unit-tests.png)

### Tests_Example

**!!!ATTENTION!!!** IP field at the top - the one used before - is here disabled.

The rest is just as simple as GET_Example. The amount of tests and their properties
is to be set by the user.

![unit-tests-data](/readme_files/unit-tests-data.png)

now PRESS **GREEN BUTTON**...

... and the Status Code's color tells if the test passed or not:
	- green -> OK
	- red 	-> NOT OK

![unit-tests-results](/readme_files/unit-tests-results.png)

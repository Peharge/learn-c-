Programming a simple weather display in C++ requires that you access an API to get the weather data, since C++ itself has no built-in functions to access weather data directly. One of the most popular APIs you can use for weather data is the OpenWeatherMap API.

Here is a simple flow to program a weather display in C++:

To make HTTP requests in C++, you will use `libcurl`. Here are the steps to install:

- **Windows (with vcpkg):**
    1. Install [vcpkg](https://github.com/microsoft/vcpkg).
    2. Install `libcurl` with the command:
       ```bash
       vcpkg install curl
       ```

- **Linux (Ubuntu):**
  ```bash
  sudo apt-get install libcurl4-openssl-dev
  ```

- **Mac:**
  ```bash
  brew install curl
  ```
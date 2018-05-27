# Multi Numeral Systems Converter 

Multi Numeral Systems Converter is application written in GTKMM 3 (GTK+3 binding to C++) which allows user to convert number from binary, octagonal, decimal, hexadecimal system to another system.

## Building application

### Install GTKMM 3 and pkg-config

This step depends on your operating system. Linux distributions (and other *nix operating systems) should have GTKMM 3 and pkg-config in repository/ports (eg. libgtkmm-3.0-dev and pkg-config packages in Debian based or x11-toolkits/gtkmm3.0 and devel/pkg-config ports in FreeBSD). On macOS you can use package manager like Homebrew. Windows GTKMM binaries can be found on GTKMM page: https://www.gtkmm.org 

### Clone this repository and go to the created directory
```sh
git clone https://github.com/BlackDragonDev/MultiNumeralSystemsConverter.git && cd MultiNumeralSystemsConverter
```

### Compile using make
```sh
make
```

### After successfull compilation run application
```sh
./multinumeralsystemsconverter
```
## Instructions
Select input and target numeral system, write value and click "Convert" button.

## License
Numeral Systems Converter is distributed under MIT license. For more informations read LICENSE file.
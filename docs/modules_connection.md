# For Arduino (old version)

## SR04
Grnd -> - -> GND  
Echo -> D11 (MOSI)  
Triq -> D12 (MISO)  
VCC -> + -> 5V  

## GY-511 (LSM303DLHCTR)
VIN -> + -> 5V  
GND -> - -> GND  
SCL -> SCL  
SDA -> SDA  


# For ESP32
## SR04
Grnd -> - -> GND
Echo -> GPIO 18 (G18)
Triq -> GPIO 5  (G5)
VCC -> + -> 5V  

## GY-511 (LSM303DLHCTR)
SCL (default is GPIO 22)  -> SCL
SDA (default is GPIO 21) -> SDA

# Potentiometer PT-12
Bottom Left -> 5V
Bottom Right -> GND
Top -> G34 (but could be another one, see the code)
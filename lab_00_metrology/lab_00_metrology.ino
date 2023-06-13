#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

// pin assignments for voltage and current with ACS723 
const int volt_in = A3; 
const int curr_in = A4; 

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("test");
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  // ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();


  analogReadResolution(12); 

  Serial.println("           INA219:              ACS723:");
  Serial.println("time (ms), curr (mA), volt (V), curr (?), volt (?)");

} // end function setup()


struct electrical_measurement
{
  long current_mA, voltage_V, power_mW;  
};

// prototype function for INA219 reading
electrical_measurement INA219reading() ;

// prototype function for ACS723 reading
electrical_measurement ACS723reading(); 



  int interval = 500; // writes measurements every XX ms
  int present = millis(); 
  int due = present += interval; 

  int averaging_index = 0; // average over the last X samples
  int const num_samples = 10; // number of samples to average over

  float ina219curr_samples[num_samples];
  float ina219volt_samples[num_samples];
  float acs723curr_samples[num_samples];
  float acs723volt_samples[num_samples];  


void loop() {
  electrical_measurement ina219data; 
  ina219data = INA219reading(); 
  
  electrical_measurement acs723data; 
  acs723data = ACS723reading(); 

  // ina219curr_samples[averaging_index] = ina219data.current_mA; 
  // ina219volt_samples[averaging_index] = ina219data.voltage_V; 
  
  acs723curr_samples[averaging_index] = acs723data.current_mA; 
  acs723volt_samples[averaging_index++] = acs723data.voltage_V; 
if (averaging_index >= num_samples){
    averaging_index = 0; 
    
  }


  present = millis(); 
  if (present >= due){
    String write_line = "";
    write_line += present; 
    /*
    // INA219
    float current = 0; 
    float voltage = 0; 
    for (int ii = 0; ii < num_samples; ii++){ // sum last X current samples
      current += ina219curr_samples[ii];
      voltage += ina219volt_samples[ii];
    } // end INA219 current sample sum
    current = current / float(num_samples); 
    voltage = voltage / float(num_samples);
    write_line += ", ";
    write_line += current; 
    write_line += ", ";
    // write_line += voltage; 
    write_line += ina219volt_samples[9]; 
*/

     // ACS723
    float current = 0; 
    float voltage = 0; 
    for (int ii = 0; ii < num_samples; ii++){ // sum last X current samples
      current += acs723curr_samples[ii];
      voltage += acs723volt_samples[ii];
      delay(10); 

    } // end ACS723 current sample sum
    current = current / float(num_samples); 
    voltage = voltage / float(num_samples);
    write_line += ", ";
    write_line += current; 
    write_line += ", ";
    write_line += voltage; 
    

    Serial.println(write_line); 

Serial.println(due); 
    due += interval; 
    Serial.println(due);
  }
  
  delay(100); 
  // Serial.println(present); 
} // end function loop()


// Adafruit_INA219 ina219 ;

electrical_measurement INA219reading(){
  // electrical_measurement data; //creates empty object 'data' of type electrical_measurement

  // float shuntvoltage;
  // float busvoltage ;
  // float solar_panel_voltage ;

  // shuntvoltage = ina219.getShuntVoltage_mV();
  // busvoltage = ina219.getBusVoltage_V();
  // //power_mW = ina219.getPower_mW();
  // data.voltage_V = busvoltage + (shuntvoltage / 1000);
  // data.current_mA = ina219.getCurrent_mA();
  
  // return data;
  
} // end function INA219reading()

electrical_measurement ACS723reading(){
  electrical_measurement data; //creates empty object 'data' of type electrical_mreasurement
  
  
  // The on-board ADC is 12-bits -> 2^12 = 4096 -> 3300 mV / 4096 counts 0.8 mV/count
  int volt_counts; 
  volt_counts = analogRead(volt_in);
  float volt_sensitivity = 0.8; 
  data.voltage_V = volt_counts * volt_sensitivity; 

  // need to adjust curr_sensitivity to account for sensor gain
  int curr_counts; 
  curr_counts = analogRead(curr_in); 
  float curr_sensitivity = 1; 
  float Vref = 0; 
  data.current_mA = (curr_counts*volt_sensitivity-Vref)*curr_sensitivity; 

  return data; 
}



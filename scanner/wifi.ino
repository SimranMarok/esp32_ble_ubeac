void wifi_setup() {
  delay(4000);   //Delay needed before calling the WiFi.begin

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void send_data(float value, String my_str) {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    String final_data = my_str + String(value);
    HTTPClient http;

    http.begin(url);  //Specify destination for HTTP request
    http.addHeader("Content-Type", "text/plain");             //Specify content-type header

    int httpResponseCode = http.POST(final_data);   //Send the actual POST request

    if (httpResponseCode > 0) {
      String response = http.getString();                       //Get the response to the request
      Serial.println(httpResponseCode);   //Print return code
      Serial.println(response);           //Print request answer
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();  //Free resources
  } else {
    Serial.println("Error in WiFi connection");
  }
  delay(10000);  //Send a request every 10 seconds
}

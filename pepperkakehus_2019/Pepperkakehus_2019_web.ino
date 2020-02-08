#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "toggle_button.h"
#include "tune_player.h"

#define WHITE_LED 12
#define WHITE_LED_2 12
#define WHITE_BUTTON 8
#define RED_BUTTON 2

const char *ssid = "nielsen";
const char *password = "fritsnielsen";

WebServer server(80);

// See ReadMe.adoc

// For alternating LEDs
//const int ledPins[] = {10,11};
//const int ledPinSize = 2;
// For single led

const int ledPins[] = {13};
const int ledPinSize = 1;

TunePlayer tunePlayer(12, ledPins, ledPinSize);

void redToggle(bool state)
{
  if (state)
  {
    tunePlayer.startTune("All I want for Christmas");
  }
  else
  {
    tunePlayer.stopTune();
  }
}

void whiteToggle(bool state)
{
  digitalWrite(WHITE_LED, state ? HIGH : LOW);
  digitalWrite(WHITE_LED_2, state ? HIGH : LOW);
}

ToggleButton redButton(RED_BUTTON, redToggle);
ToggleButton whiteButton(WHITE_BUTTON, whiteToggle);

void handleRoot()
{
  //digitalWrite(led, 1);
  if (server.args() > 1 && server.argName(0) == "command" && server.argName(1) == "song")
  {
    if (server.arg(0) == "start")
    {
      tunePlayer.startTune(server.arg(1));
    }
  }
  else if (server.args() > 0 && server.argName(0) == "command" && server.arg(0) == "stop")
  {
    tunePlayer.stopTune();
  }

  server.send(200, "text/html",
              "<html>\
<head>\
    <meta charset=\"utf-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\
    <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css\">\
</head>\
  <body>\
    <h1>Pepperkakehuskontrollen</h1>\
    <p><a class=\"btn btn-success btn-block\" href=\"/?command=start&song=all_i_want_for_christmas\">Spill All I want for Christmas</a></p>\
    <p><a class=\"btn btn-success btn-block\" href=\"/?command=start&song=jingle_bells\">Spill Jingle bells</a></p>\
    <p><a class=\"btn btn-danger btn-block\" href=\"/?command=stop\">Stopp</a></p>\
  </body>\
  </html>");
  //digitalWrite(led, 0);
}

void setup()
{
  Serial.begin(115200);

  tunePlayer.stopTune();
  pinMode(WHITE_LED, OUTPUT);
  pinMode(WHITE_LED_2, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32"))
  {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  tunePlayer.loop();
  redButton.loop();
  whiteButton.loop();
  server.handleClient();
}

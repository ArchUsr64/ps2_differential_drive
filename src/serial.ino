void flush_serial() {
  while (Serial.available()) {
    Serial.read();
  }
}

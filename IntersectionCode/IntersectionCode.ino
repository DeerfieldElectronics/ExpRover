int count = 0;

count++;
if (count == 1){
  stop();
  delay(5000);
  forward();
  delay(500);
}
else{
  forward();
  delay(500);
}


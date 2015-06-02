run() {
	rm *.class
	cp src/PathDefense.java ../PathDefense
	javac PathDefense.java
	java -jar tester.jar -seed 25 -delay 300 -exec "java PathDefense"
}
run;

run() {
	rm *.class
	cp src/PathDefense.java ../PathDefense
	javac PathDefense.java
	java -jar tester.jar -seed 41221232 -delay 1 -exec "java PathDefense"
}
run;


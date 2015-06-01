run() {
	rm *.class
	cp src/PathDefense.java ../PathDefense
	javac PathDefense.java
	java -jar tester.jar -seed 10 -delay 2 -exec "java PathDefense"
}
run;

run() {
	rm *.class
	cp src/PathDefense.java ../PathDefense
	javac PathDefense.java
	java -jar tester.jar -seed 41221232 -delay 1 -exec "java PathDefense"
}

simul() {
	rm *.class
	cp src/PathDefense.java ../PathDefense
	javac PathDefense.java
	for i in {1..10}
			 do
				 nohup java -jar tester.jar -seed $i -delay 0 -exec "java PathDefense" | grep Score 
	done
}
#simul
run;


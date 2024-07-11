.PHONY: run

run:
	g++ -std=c++17 -o $(filter-out $@,$(MAKECMDGOALS)).out $(filter-out $@,$(MAKECMDGOALS)).cpp && ./$(filter-out $@,$(MAKECMDGOALS)).out
clean:
	rm -f *.out
	clear
%:
	@:

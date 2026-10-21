all: store_app

store_app: main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp
	g++ main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp -o store_app

clean:
	rm -f store_app
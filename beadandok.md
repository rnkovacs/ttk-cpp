# Beadandók

Az elkészült feladatokat a `rekanikolett@gmail.com` cimre várom, ideális esetben `[TTK C++]` kezdetű tárggyal.

Az eddig gyűjtött pontjaitokat megnézhetitek itt: [ponttáblázat](https://goo.gl/4ngAQp).

## 0. Mario piramis

**Beadási határidő**: február 27.

Rajzoljuk ki a terminálra a Mario játékból ismert lépcsősort! A magasságát a felhasználótól kérjük be. (1 pont)

<img src="http://www.infendo.com/wp-content/uploads/2008/06/mario.png" height="220"> <img src="http://www.korenlc.com/wp-content/uploads/2014/03/mario.jpg1.png" height="220">

Kérdezzük meg a felhasználótól, hogy fél- vagy egész piramist szeretne-e látni. Ha egészet, akkor a lépcsősor tükörképe is jelenjen meg a jobboldalon. A két fél legyen vizuálisan elkülönitve. (+ 2 pont)

```
   ## ##
  ### ###
 #### ####
##### #####
```

## 1. Hitelkártya

**Beadási határidő**: március 13.

Irjunk egy programot, ami eldönti a felhasználótól beolvasott kártyaszámról, hogy
valódi-e (5 pont). A beolvasott szám tárolására használjunk `long long` tipust.
A validálást a [Luhn-algoritmussal](https://hu.wikipedia.org/wiki/Luhn-formula) végezzük!

Legyen szó első körben MasterCard kártyákról. Ezekről azt tudjuk,
hogy 16 számjegyből állnak, és az első két számjegyük az alábbi lehetőségek közül
kerül ki: 51, 52, 53, 53, 55. A program viselkedése legyen a következő:

```
$ ./credit
Card number: -378
Invalid

$ ./credit
Card number: foo
Invalid

$ ./credit
Card number: 4716904945120806
Invalid

$ ./credit
Card number: 5531762164721732
Valid
```

(+ 2 pont) Ismerjünk fel más kártyatipusokat is! A Visa kártyák számai 4-essel
kezdődnek, és vagy 13, vagy 16 számjegyből állnak. Az American Express kártyák
15 számjegyből állnak, és 34-re vagy 37-re kezdődnek.

```
$ ./credit
Card number: 4716904945120806
Visa

$ ./credit
Card number: 5531762164721732
MasterCard

$ ./credit
Card number: 370214777555219
American Express

$ ./credit
Card number: 4716904945120807
Invalid

$ ./credit
Card number: 4716904
Invalid
```
Teszteléshez valid hitelkártya-számokat [itt](http://www.getcreditcardnumbers.com/how-to-get-a-master-card-credit-card) találtok.

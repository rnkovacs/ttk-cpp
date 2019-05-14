### Mintavizsga: Webáruház

A feladat egy `Webstore` osztály irása, ami `Product` objektumok listáját tárolja.  

Egy `Product` a következő jellemzőkkel rendelkezik: 
  - `name` (string),
  - `price` (int),
  - `code` (string),
  - `added` (dátum),
  - `sold` (dátum).  

A cél az, hogy a `webstore.cpp` fájl módositás nélkül lefusson és jó eredményeket adjon.

**2-eshez szükséges funkciók:**
  - A `list` metódus kiirja a termékek információit a terminálra. Pl.  
    `Lampa	3000	POR873	2019-03-21	2019-05-02`
  - Az `add` metódus paraméterként megkap minden információt egy termékről,
    és hozzáadja új termékként a webáruházhoz. Az eladás dátuma opcionális,
    ha azt nem kapja meg a függvény, akkor tárolja el a `0 0 0` dátumot.
  - A `readFrom` metódus a paraméterként kapott fájlból olvassa be az adatokat.
    Minden sor egy terméket jellemez. Feltételezhetjük, hogy az adatok 
    hiánytalanok és helyesek. Az eladási dátum opcionalitása itt is úgy jelenik
    meg, hogy `0 0 0` szerepel helyette.

**3-mashoz szükséges funkciók:**
  - A `sort` metódus a következő szempontok alapján rendezi a termékinfókat:
      - termék neve,
      - ha az egyezik: termék ára,
      - ha az is egyezik: kód szerint.

**4-eshez szükséges funkciók:**
  - A `remove` metódus egy termékkódot kap, és kitörli a webáruházból a 
    megfelelő terméket. Ha nem található ilyen termék, akkor nem csinál semmit.

**5-öshöz szükséges funkciók:**
  - Az `income` metódus két paramétert vár: egy évet és egy hónapot. Erre a
    hónapra összesiti és visszaadja a webáruház árbevételét (értsd: eladott
    termékek árainak összege). Ha hónapként `0` értéket kap, akkor egész évre
    vonatkozólag számol.

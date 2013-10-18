Rozpoznawanie dzwieku - projekt na algo
=======================================


Na środę (na prezentację) robimy program, który czyta plik wav z dysku i wyswietla FFT kolejnych 5s fragmentow po jakiejs normalizacji, odszumianiu etc.

Piszemy w C++

Chwilowy podział pracy:
* Francuz odczytywanie dzwieku
    - zwraca
        ```
            vector<double> sound
        ```

* Glapa FFT etc
    - zwraca
    ```
        vector<vector<double> >  FFTs
    ```
* Morawski, Bartosik wyświetlanie wykresów


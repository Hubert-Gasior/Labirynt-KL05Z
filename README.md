# Gra zręcznościowa "Labirynt" na mikrokontrolerze KL05Z

Autorzy: Hubert Gąsior, Krystian R

## Spis treści
1. [Opis projektu](#opis-projektu)
2. [Wymagania sprzętowe](#wymagania-sprzętowe)
3. [Schemat połączeń](#schemat-połączeń)
4. [Opis oprogramowania](#opis-oprogramowania)
5. [Instrukcja użytkowania](#instrukcja-użytkowania)
6. [Testy](#testy)

## Opis projektu
Gra zręcznościowa "Labirynt" polega na prowadzeniu kulki przez labirynt za pomocą ruchu platformy. Platforma jest kontrolowana przez joystick analogowy, który steruje dwoma serwomechanizmami. Mikrokontroler KL05Z jest używany do zarządzania serwomechanizmami i odczytu danych z joysticka.

## Wymagania sprzętowe
- Mikrokontroler KL05Z
- Dwa serwomechanizmy (180° lub 360°)
- Joystick analogowy
- Plansza z labiryntem
- Przewody połączeniowe
- Zasilanie (6V dla serw i 3.3V dla mikrokontrolera i joysticka)

## Schemat połączeń
1. Podłączenie joysticka:
    - Wyjście X joysticka do analogowego wejścia A0 mikrokontrolera.
    - Wyjście Y joysticka do analogowego wejścia A1 mikrokontrolera.
    - Zasilanie joysticka (3.3V) do zasilania mikrokontrolera.
2. Podłączenie serwomechanizmów:
    - Sterowanie serwomechanizmami poprzez odpowiednie piny PWM mikrokontrolera.
    - Zasilanie serwomechanizmów do zewnętrznego źródła zasilania (6V).

## Opis oprogramowania
Oprogramowanie zostało napisane w języku C i obejmuje następujące moduły:
1. **Moduł odczytu joysticka**: Odczyt analogowych wartości z osi X i Y joysticka.
2. **Moduł sterowania serwomechanizmami**: Sterowanie serwomechanizmami na podstawie wartości odczytanych z joysticka.
3. **Główny program**: Inicjalizacja mikrokontrolera, konfiguracja przerwań i pętla główna gry.

## Instrukcja użytkowania
1. Podłącz zasilanie mikrokontrolera i serwomechanizmów.
2. Ustaw planszę z labiryntem na platformie sterowanej przez serwomechanizmy.
3. Za pomocą joysticka steruj platformą, aby prowadzić kulkę przez labirynt.

## Testy
Przeprowadzono testy w następujących obszarach:
1. **Testy funkcjonalne**: Sprawdzenie poprawności działania joysticka oraz sterowania serwomechanizmami.
2. **Testy integracyjne**: Weryfikacja współdziałania wszystkich modułów oprogramowania.
3. **Testy wydajnościowe**: Sprawdzenie płynności ruchu platformy przy różnych ustawieniach joysticka.

# Aplikacja obsługująca wyświetlacz OLED ze sterownikiem SH1106

## TODO: Update project documentation. Add missing README.md in components


Library for driving display with SH1106 driver.

```plantuml

@startuml

package "DisplayComm" {
    () DisplayCommIf #palegreen
    () DisplayResetIf #palegreen
    () DisplayDataCmdIf #palegreen
}

package "Sh1106" {

}

package "MonochromeGraphicDisplay" {
    () DisplayDriverIf #palegreen
    () MonochromeGraphicDisplayIf #palegreen

    MonochromeGraphicDisplayIf o-- DisplayDriverIf
}

package "DisplayApp" {
        [AppImpl]

        AppImpl *-- DisplayDriverIf
        AppImpl *-- DisplayResetIf
        AppImpl *-- DisplayCommIf
        AppImpl *-- DisplayDataCmdIf
        AppImpl *-- MonochromeGraphicDisplayIf
}

Sh1106 o-- DisplayResetIf
Sh1106 o-- DisplayCommIf

@enduml


```

Init -> Sh1106
setCommInterface -> Sh1106()
setDisplayOn -> Sh1106
setColorInverted -> Sh1106
setContrast 
updateScreen

Graphical Screen:
fill
clear
drawPixel
drawLine
writeChar
writeString
displayPhoto

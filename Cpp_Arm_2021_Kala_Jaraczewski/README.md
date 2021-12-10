# Aplikacja obsługująca wyświetlacz OLED ze sterownikiem SH1106

Library for driving display with SH1106 driver.

```plantuml

@startuml

package "DisplayComm" {
    () DisplayCommIf #palegreen
    () DisplayResetIf #palegreen
    () DisplayDataCmdIf #palegreen
}

package "GraphicalScreen" {
    () GraphicalScreenDriverIf #palegreen
    () GraphicalScreenIf #palegreen

    GraphicalScreenIf o-- GraphicalScreenDriverIf
}



package "Sh1106Component" {
    
        [Sh1106]

        Sh1106 --> GraphicalScreenDriverIf
        Sh1106 o-- DisplayResetIf
        Sh1106 o-- DisplayCommIf

}

package "DisplayApp" {
        [AppImpl]

        AppImpl *-- Sh1106
        AppImpl *-- DisplayResetIf
        AppImpl *-- DisplayCommIf
        AppImpl *-- DisplayDataCmdIf
        AppImpl *-- GraphicalScreenIf
}

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

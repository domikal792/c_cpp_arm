# Monochrome View component

```plantuml

@startuml

package "MonochromeView " {
    package "Inc" {
        () ViewIf #palegreen

        [ConstView]
        [DynamicView]

        ConstView -u-> ViewIf
        DynamicView -u-> ViewIf
    }
}

@enduml

```

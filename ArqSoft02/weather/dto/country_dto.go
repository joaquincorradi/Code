package dto

type Country struct {
	Id             string         `json:"id"`
	Name           string         `json:"name"`
	Geoinformation Geoinformation `json:"geo_information"`
}

type Geoinformation struct {
	Location Location `json:"location"`
}

type Location struct {
	Latitude  float64 `json:"latitude"`
	Longitude float64 `json:"longitude"`
}

package dto

type User struct {
	Id       uint   `json:"id"`
	Nickname string `json:"nickname"`
	Country  string `json:"country_id"`
}

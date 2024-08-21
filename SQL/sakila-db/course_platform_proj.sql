create table course
(
    course_id    int auto_increment
        primary key,
    title        varchar(255) not null,
    description  text         null,
    requirements text         null,
    rating       tinyint      null,
    course_image varchar(255) null,
    category     varchar(100) null,
    constraint course_id
        unique (course_id),
    constraint title
        unique (title)
);

create table content
(
    content_id int auto_increment
        primary key,
    text       text         null,
    picture    varchar(255) null,
    video      varchar(255) null,
    course_id  int          not null,
    constraint content_id
        unique (content_id),
    constraint content_ibfk_1
        foreign key (course_id) references course (course_id)
);

create index course_id
    on content (course_id);

create table user
(
    user_id  int auto_increment
        primary key,
    name     varchar(50)  not null,
    lastname varchar(50)  not null,
    email    varchar(255) not null,
    password varchar(100) not null,
    constraint email
        unique (email),
    constraint user_id
        unique (user_id)
);

create table role
(
    role_id int auto_increment
        primary key,
    name    varchar(50) not null,
    user_id int         not null,
    constraint role_id
        unique (role_id),
    constraint role_ibfk_1
        foreign key (user_id) references user (user_id)
);

create index user_id
    on role (user_id);

create table user_course
(
    user_id         int  not null,
    course_id       int  not null,
    enrollment_date date null,
    primary key (user_id, course_id),
    constraint user_course_ibfk_1
        foreign key (user_id) references user (user_id),
    constraint user_course_ibfk_2
        foreign key (course_id) references course (course_id)
);

create index course_id
    on user_course (course_id);





CREATE TABLE time_dimension(
  time_key Number(5),
  day Number(5),
  month Number(5),
  quarter Number(5),
  year Number(5)
);
desc time_dimension;
alter table time_dimension
add constraint pk_time_dimension
primary key (time_key);
desc time_dimension;

CREATE TABLE location_dimension(
  location_key Number(5),
  street varchar(10),
  city varchar(10),
  province varchar(10),
  country varchar(10)
);
desc location_dimension;
alter table location_dimension
add constraint pk_location_dimension
primary key (location_key);
desc location_dimension;
CREATE TABLE item_dimension(
  item_key Number(5),
  item_name varchar(10),
  brand varchar(10),
  type varchar(10),
  supplier_type varchar(10)
);
desc item_dimension;
alter table item_dimension
add constraint pk_item_dimension
primary key(item_key); 
desc item_dimension;

create table branch_dimension(
   branch_key NUMBER(5),
   branch_name varchar(20),
   branch_type varchar(20)
);
desc branch_dimension; 
alter table branch_dimension
add constraint pk_branch_dimension
primary key (branch_key); 
desc branch_dimension;
show tables;
create table sales_fact(
  id number(5),
  dollar_sold number(7,2),
  units_sold number(5),
  time_key number(5),
  item_key number(5),
  location_key number(5),
  branch_key number (5)
);
desc sales_fact;
alter table sales_fact
add constraint pk_sales_fact
primary key(id);
desc sales_fact;

alter table sales_fact 
add constraint fk_time_dimension_sales_fact
foreign key(time_key) references time_dimension(time_key);
desc sales_fact;

alter table sales_fact
add constraint fk_item_dimension_sales_fact
foreign key(item_key) references item_dimension(item_key);

alter table sales_fact
add constraint fk_branch_dimension_sales_fact
foreign key(branch_key) references branch_dimension(branch_key);
alter table sales_fact
add constraint fk_location_dimension_sales_fact
foreign key(location_key) references location_dimension(location_key);
desc sales_fact; 

insert into time_dimension values (1,6,5,1,2022);
insert into time_dimension values (2,3,4,1,2020);
insert into time_dimension values (3,2,6,2,2021);
insert into time_dimension values (4,4,2,1,2020);
show time_dimension;
select * from oracledb;
show tables;
select owner,location_dimension from oracledb; 
insert into location_dimension values (1, 'NITW street', 'Warangal', 'Telangana', 'India');
alter table location_dimension
modify street varchar (255);

alter table location_dimension
modify city varchar (255);
alter table location_dimension
modify province varchar (255);
alter table location_dimension
modify country varchar (255);
insert into location_dimension values (1, 'NITW street', 'Warangal', 'Telangana', 'India');
insert into location_dimension values (2, 'HanamKonda street', 'Warangal', 'Telangana', 'India');
delete from location_dimension where location_key = 2;

insert into location_dimension values (4, 'rajgrih street', 'Kushi Nagar', 'Uttar Pradesh', 'India');
select * from location_dimension;
delete from location_dimension where location_key = 3;
delete from location_dimension where location_key = 4;
delete from location_dimension where location_key = 2;
insert into location_dimension values (2, 'HanamKonda street', 'Warangal', 'Telangana', 'India');
insert into location_dimension values (3, 'Raj Nagar', 'Aurangabad', 'Bihar', 'India');
insert into location_dimension values (4, 'rajgrih street', 'Kushi Nagar', 'Uttar Pradesh', 'India');
select * from location_dimension;
insert into item_dimension values (1, 'laptop', 'HP', 'Computer', 'electrical');
insert into item_dimension values (2, 'desktop', 'DELL', 'Computer', 'electrical');
delete from location_dimension where location_key = 2;
insert into item_dimension values (3, 'printer', 'DekJet', 'device', 'electrical');

select * from item_dimension; 
delete from item_dimension where item_key = 3;
insert into item_dimension values (4, 'Keyboard', 'Zebro', 'device', 'electrical');

insert into branch_dimension values (1, 'brA', 'Elect');
insert into branch_dimension values (2, 'brB', 'Elect2');
insert into branch_dimension values (3, 'brC', 'Elect3');
insert into branch_dimension values (4, 'brA', 'Elect');
select * from branch_dimension; 
delete from branch_dimension where branch_key = 4; 

insert into sales_fact values (1, 1000, 50, 1, 1, 1, 1);
insert into sales_fact values (2, 3500, 20, 1, 2, 1, 4);
insert into sales_fact values (3, 5600, 100, 2, 3,2, 3);
insert into sales_fact values (4, 1000, 50, 3, 4, 3, 2);
select * from sales_fact; 
select sum(f.units_sold) as UnitSold, t.city from sales_fact f, location_dimension t where f.location_key = t.location_key
group by cube(t.city);
select sum(f.units_sold) as UnitSold, (i.item_name, t.city) from sales_fact f, t.city from sales_fact f, item_dimension i where f.item_key = i.item_key
group by cube(i.item_name);
select * from sales_fact;  

create table game(
   game_id varchar(10),
   game_name varchar(255)
);

alter table game
add constraint pk_game
primary key (game_id);
desc game;


create table game_location(
   location_key varchar(10),
   city varchar(255)
);
alter table game_location
add constraint pk_game_location
primary key (location_key);

desc game_location; 

create table game_date (
    date_id varchar(10),
    day number (10),
    month number(10),
    year number(10)
);
alter table game_date
add constraint pk_game_date
primary key (date_id); 

desc game_date;

create table game_sales (
    game_id varchar(10),
    date_id varchar(10),
    spectator_id varchar(10),
    location_id varchar(10),
    count number(10),
    charge number(10)
);

alter table game_sales
add constraint pk_game_sales
primary key (game_id);

alter table game_sales
add constraint location_game_sales
foreign key(location_key) references game_location(location_key);

desc game_sales; 

alter table game_sales 
add constraint game_game_sales
foreign key(game_id) references game(game_id);
desc game_sales;

alter table game_sales 
add constraint game_location_game_sales
foreign key(location_key) references game_location(location_key);
desc game_location; 
select * from game_location; 
alter table game_sales
add constraint location_game_sales
foreign key(location_key) references game_location(location_key);

create table game_spectators(
    spec_id varchar(10),
    type varchar(255)
);

alter table game_spectators
add constraint pk_game_spectators
primary key (spec_id); 
desc game_sales; 
alter table game_sales
add constraint game_date_game_sales 
foreign key (date_id) references game_date(date_id);

alter table game_sales
add constraint game_location_game_sales
foreign key(location_id) references game_location(location_key);

alter table game_sales
add constraint game_spectators_game_sales
foreign key(spectator_id) references game_spectators(spec_id); 

insert into game values ('G1','Game Name');
delete from game where game_id = 'G1';
insert into game values ('G1','Cricket');
insert into game values ('G2','Table Tennis');
insert into game values ('G3','Hockey');
insert into game values ('G4','Badminton');
insert into game values ('G5','Polo');

insert into game_location values('L1','Delhi');
insert into game_location values('L2','GM_PLACE');
insert into game_location values('L3','Mumbai');
insert into game_location values('L4','Kolkata');
insert into game_location values('L5','Ahmedabad');

insert into game_date values ('D1',4,8,2020);
insert into game_date values ('D2',5,9,2022);
insert into game_date values ('D3',3,2,2022);
insert into game_date values ('D4',3,2,2022);
insert into game_date values ('D5',7,1,2020);
insert into game_date values ('D6',7,1,2010);
insert into game_date values ('D7',11,12,2013);

insert into game_spectators values ('S1','Adult');
insert into game_spectators values ('S2','Senior');
insert into game_spectators values ('S3','Adult');
insert into game_spectators values ('S4','Adult');
insert into game_spectators values ('S5','Senior');

insert into game_sales values('G1','D2','S4','L2',500,2000);
insert into game_sales values('G2','D2','S4','L2',1500,200);
insert into game_sales values('G3','D3','S4','L3',600,300);
insert into game_sales values('G5','D1','S4','L2',700,800);

select sum("A1".charge*"A2".count)
from "SYSTEM"."game_sales" "A1",
"SYSTEM"."game_location" "A2",
"SYSTEM"."game_spectators" "A3",
"SYSTEM"."game_date" "A4",
where 
(
  "A2".city = 'GM_PLACE' and
  "A4".year = '2020' and
  "A3".type = 'Adult'
)
group by
"A2".city; 
select * from game;
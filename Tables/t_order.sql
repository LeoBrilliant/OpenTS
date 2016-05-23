-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 2016-05-23 16:01:59
-- 服务器版本： 10.1.13-MariaDB
-- PHP Version: 5.6.20

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `test`
--

-- --------------------------------------------------------

--
-- 表的结构 `t_order`
--

DROP TABLE IF EXISTS `t_order`;
CREATE TABLE IF NOT EXISTS `t_order` (
  `ClientID` int(11) DEFAULT NULL,
  `InstructionType` int(11) DEFAULT NULL,
  `InstrumentID` varchar(50) DEFAULT NULL,
  `Direction` varchar(1) DEFAULT NULL,
  `OffsetFlag` varchar(1) DEFAULT NULL,
  `OrderPrice` double(22,6) DEFAULT NULL,
  `Volume` int(11) DEFAULT NULL,
  `OrderID` int(11) DEFAULT NULL,
  `LocalOrderID` int(11) DEFAULT NULL,
  `OrderTimePoint` bigint(20) DEFAULT NULL,
  `VolumeLeft` int(11) DEFAULT NULL,
  `CancelTimePoint` bigint(20) DEFAULT NULL,
  `OrderStatus` varchar(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

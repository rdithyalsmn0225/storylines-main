-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 09, 2024 at 04:11 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `storylines`
--

-- --------------------------------------------------------

--
-- Table structure for table `ajail_logs`
--

CREATE TABLE `ajail_logs` (
  `id` int(11) NOT NULL,
  `JailedDBID` int(11) NOT NULL,
  `JailedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `JailedBy` varchar(32) NOT NULL,
  `Time` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `bannedlist`
--

CREATE TABLE `bannedlist` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `IpAddress` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `ban_logs`
--

CREATE TABLE `ban_logs` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `businesses`
--

CREATE TABLE `businesses` (
  `BusinessDBID` int(11) NOT NULL,
  `BusinessOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorX` float NOT NULL DEFAULT 0,
  `BusinessInteriorY` float NOT NULL DEFAULT 0,
  `BusinessInteriorZ` float NOT NULL DEFAULT 0,
  `BusinessInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `BusinessEntranceX` float NOT NULL DEFAULT 0,
  `BusinessEntranceY` float NOT NULL DEFAULT 0,
  `BusinessEntranceZ` float NOT NULL DEFAULT 0,
  `BusinessName` varchar(90) NOT NULL DEFAULT 'Nameless',
  `BusinessType` int(11) NOT NULL DEFAULT 0,
  `BusinessLocked` tinyint(1) NOT NULL DEFAULT 0,
  `BusinessEntranceFee` int(11) NOT NULL DEFAULT 1,
  `BusinessLevel` int(11) NOT NULL DEFAULT 0,
  `BusinessMarketPrice` int(11) NOT NULL DEFAULT 5000,
  `BusinessCashbox` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts` int(11) NOT NULL DEFAULT 0,
  `BusinessPointX` float NOT NULL DEFAULT 0,
  `BusinessPointY` float NOT NULL DEFAULT 0,
  `BusinessPointZ` float NOT NULL DEFAULT 0,
  `BusinessRobberyTime` int(11) NOT NULL DEFAULT 0,
  `BusinessShipments` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `businesses`
--

INSERT INTO `businesses` (`BusinessDBID`, `BusinessOwnerDBID`, `BusinessInteriorX`, `BusinessInteriorY`, `BusinessInteriorZ`, `BusinessInteriorWorld`, `BusinessInteriorIntID`, `BusinessEntranceX`, `BusinessEntranceY`, `BusinessEntranceZ`, `BusinessName`, `BusinessType`, `BusinessLocked`, `BusinessEntranceFee`, `BusinessLevel`, `BusinessMarketPrice`, `BusinessCashbox`, `BusinessProducts`, `BusinessPointX`, `BusinessPointY`, `BusinessPointZ`, `BusinessRobberyTime`, `BusinessShipments`) VALUES
(64, 0, 411.446, -23.1505, 1001.8, 12364, 2, 2070.63, -1793.94, 13.5469, '', 11, 0, 0, 0, 100000, 0, 100, 414.393, -19.9093, 1001.6, 0, 0),
(65, 0, -45.8394, 2.1805, 203.263, 5991, 17, 2070.11, -1785.35, 13.5547, '', 7, 0, 0, 0, 30000, 500, 100, -53.6147, -0.810779, 203.333, 0, 0),
(66, 0, 1363.76, 1707.42, 434.979, 5355, 2, 2096, -1211.58, 23.963, '', 12, 0, 0, 0, 50000, 0, 100, 1356.15, 1703.95, 435.119, 0, 0),
(67, 0, 772.238, -5.385, 1000.73, 9125, 5, 1234.7, -1158.35, 23.5415, '', 13, 0, 0, 0, 50000, 0, 100, 756.728, 5.26245, 1000.7, 0, 0),
(68, 1, -45.8394, 2.1805, 203.263, 13758, 17, 1112.98, -1158.96, 23.8281, '', 7, 0, 0, 0, 50000, 1000, 100, -53.5613, -0.883306, 203.263, 0, 0),
(69, 0, -45.8394, 2.1805, 203.263, 19329, 17, 1128.72, -1270.52, 13.5469, '', 7, 0, 0, 0, 40000, 0, 100, -53.6006, -0.782024, 203.263, 0, 0),
(70, 0, 772.238, -5.385, 1000.73, 8865, 5, 2229.94, -1721.29, 13.5617, '', 13, 0, 0, 0, 40000, 0, 100, 757.315, 5.65491, 1000.7, 0, 0),
(71, 0, 207.653, -111.267, 1005.13, 3731, 15, 2244.43, -1665.39, 15.4766, '', 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `master_dbid` int(11) NOT NULL,
  `char_dbid` int(11) NOT NULL,
  `char_name` varchar(32) NOT NULL DEFAULT 'None',
  `char_masters` varchar(32) NOT NULL DEFAULT 'None',
  `create_date` varchar(60) NOT NULL DEFAULT 'None',
  `create_ip` varchar(60) NOT NULL DEFAULT 'None',
  `pAdmin` int(4) NOT NULL DEFAULT 0,
  `pLastSkin` int(11) NOT NULL DEFAULT 0,
  `pFacSkin` int(11) NOT NULL DEFAULT 0,
  `pLastPosX` float NOT NULL DEFAULT 1642.02,
  `pLastPosY` float NOT NULL DEFAULT -2334.05,
  `pLastPosZ` float NOT NULL DEFAULT 13.5469,
  `pLastInterior` int(11) NOT NULL DEFAULT 0,
  `pLastWorld` int(11) NOT NULL DEFAULT 0,
  `pLevel` int(11) NOT NULL DEFAULT 1,
  `pWantedLevel` int(11) NOT NULL DEFAULT 0,
  `pEXP` int(11) NOT NULL DEFAULT 0,
  `pAge` varchar(20) NOT NULL DEFAULT 'Invalid',
  `pOrigin` varchar(60) NOT NULL DEFAULT 'Invalid',
  `pGender` int(11) NOT NULL DEFAULT 0,
  `pStory` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pStoryTwo` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pMoney` int(11) NOT NULL DEFAULT 250,
  `pBank` int(11) NOT NULL DEFAULT 250,
  `pPaycheck` int(11) NOT NULL DEFAULT 0,
  `pPhone` int(11) NOT NULL DEFAULT 0,
  `pLastOnline` varchar(90) NOT NULL DEFAULT 'None',
  `pLastOnlineTime` int(11) NOT NULL DEFAULT 0,
  `pAdminjailed` tinyint(1) NOT NULL DEFAULT 0,
  `pAdminJailTime` int(11) NOT NULL DEFAULT 0,
  `pOfflinejailed` tinyint(1) NOT NULL DEFAULT 0,
  `pOfflinejailedReason` varchar(128) NOT NULL DEFAULT 'None',
  `pFaction` int(11) NOT NULL DEFAULT 0,
  `pFactionRank` int(11) NOT NULL DEFAULT 0,
  `pFactionSubsets` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles1` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles2` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles3` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles4` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles5` int(11) NOT NULL DEFAULT 0,
  `pVehicleSpawned` tinyint(1) NOT NULL DEFAULT 0,
  `pVehicleSpawnedID` int(11) NOT NULL DEFAULT 0,
  `pTimeplayed` int(11) NOT NULL DEFAULT 0,
  `pMaskID` int(11) NOT NULL DEFAULT 0,
  `pMaskIDEx` int(11) NOT NULL DEFAULT 0,
  `pInProperty` int(11) NOT NULL DEFAULT 0,
  `pInBusiness` int(11) NOT NULL DEFAULT 0,
  `pRadio1` int(11) NOT NULL DEFAULT 0,
  `pRadio2` int(11) NOT NULL DEFAULT 0,
  `pMainSlot` int(11) NOT NULL DEFAULT 1,
  `pSpawnPoint` int(11) NOT NULL DEFAULT 0,
  `pSpawnPointHouse` int(11) NOT NULL DEFAULT 0,
  `pWeaponsLicense` int(11) NOT NULL DEFAULT 0,
  `pDriversLicense` int(11) NOT NULL DEFAULT 0,
  `pActiveListings` int(11) NOT NULL DEFAULT 0,
  `pPrisonTimes` int(11) NOT NULL DEFAULT 0,
  `pPrison` tinyint(1) NOT NULL DEFAULT 0,
  `pInFaction` int(11) NOT NULL DEFAULT 0,
  `pRobberyCooldown` int(11) NOT NULL DEFAULT 0,
  `pFightstyle` int(11) NOT NULL DEFAULT 4,
  `pHasAoe` int(11) NOT NULL DEFAULT 0,
  `pHasInjured` tinyint(1) NOT NULL DEFAULT 0,
  `pHasDeath` tinyint(1) NOT NULL DEFAULT 0,
  `pHealth` float NOT NULL DEFAULT 100,
  `pArmor` float NOT NULL DEFAULT 0,
  `pToggleAdmin` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleHUD` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleJoined` tinyint(1) NOT NULL DEFAULT 0,
  `pHungry` int(11) NOT NULL DEFAULT 0,
  `pThirsty` int(11) NOT NULL DEFAULT 0,
  `pStamina` int(11) NOT NULL DEFAULT 0,
  `pMuscle` int(11) NOT NULL DEFAULT 0,
  `pFear` int(11) NOT NULL DEFAULT 0,
  `pRespect` int(11) NOT NULL DEFAULT 0,
  `pJobs` int(11) NOT NULL DEFAULT 0,
  `pTutorial` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`master_dbid`, `char_dbid`, `char_name`, `char_masters`, `create_date`, `create_ip`, `pAdmin`, `pLastSkin`, `pFacSkin`, `pLastPosX`, `pLastPosY`, `pLastPosZ`, `pLastInterior`, `pLastWorld`, `pLevel`, `pWantedLevel`, `pEXP`, `pAge`, `pOrigin`, `pGender`, `pStory`, `pStoryTwo`, `pMoney`, `pBank`, `pPaycheck`, `pPhone`, `pLastOnline`, `pLastOnlineTime`, `pAdminjailed`, `pAdminJailTime`, `pOfflinejailed`, `pOfflinejailedReason`, `pFaction`, `pFactionRank`, `pFactionSubsets`, `pOwnedVehicles1`, `pOwnedVehicles2`, `pOwnedVehicles3`, `pOwnedVehicles4`, `pOwnedVehicles5`, `pVehicleSpawned`, `pVehicleSpawnedID`, `pTimeplayed`, `pMaskID`, `pMaskIDEx`, `pInProperty`, `pInBusiness`, `pRadio1`, `pRadio2`, `pMainSlot`, `pSpawnPoint`, `pSpawnPointHouse`, `pWeaponsLicense`, `pDriversLicense`, `pActiveListings`, `pPrisonTimes`, `pPrison`, `pInFaction`, `pRobberyCooldown`, `pFightstyle`, `pHasAoe`, `pHasInjured`, `pHasDeath`, `pHealth`, `pArmor`, `pToggleAdmin`, `pToggleHUD`, `pToggleJoined`, `pHungry`, `pThirsty`, `pStamina`, `pMuscle`, `pFear`, `pRespect`, `pJobs`, `pTutorial`) VALUES
(18, 1, 'Jayvon_Williams', 'Bleeda', 'June 2, 2024 11:49:50', '127.0.0.1', 4, 22, 0, 2543.34, -2503.31, 13.5378, 0, 0, 8, 1, 7, '25/02/2000', 'Los Santos', 0, '', '', 22538, 224, 30, 94367, 'October 9, 2024 21:00:04', 8, 0, 0, 0, 'a', 9, 4, 2, 77, 0, 0, 0, 0, 1, 69, 48, 205458, 58, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 5, 1, 0, 0, 100, 0, 0, 0, 0, 38, 0, 0, 0, 1, 5, 1, 1),
(80, 28, 'Alonzo_Lavett', 'TayTone', 'September 28, 2024 19:00:56', '112.215.238.250', 4, 20040, 0, 2753.11, -1962.53, 13.5469, 0, 0, 1, 0, 8, '21/06/1971', 'Los Santos, Playa Del Seville', 0, '', '', 5040, 250, 0, 98958, 'October 1, 2024 21:48:44', 1, 0, 0, 0, 'None', 6, 4, 1, 0, 0, 0, 0, 0, 0, 0, 8, 343313, 40, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 100, 0, 0, 0, 19, 0, 0, 0, 0, 0, 0, 1),
(81, 29, 'Destin_Perry', 'Hustler', 'September 28, 2024 19:12:07', '104.28.156.108', 0, 7, 0, 2257.83, -1261, 23.9708, 0, 0, 1, 0, 0, '02/03/1980', 'Los Santos', 0, '', '', 250, 250, 0, 99839, 'September 29, 2024 18:36:24', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 331822, 85, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(81, 30, 'Grady_Perry', 'Hustla', 'September 28, 2024 19:13:36', '104.28.156.108', 0, 30, 0, 0, 0, 0, 0, 0, 1, 0, 0, '02/06/1980', 'Los Santos', 0, '', '', 250, 250, 0, 94491, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(81, 31, 'Jimar_Cole', 'Tweaker', 'September 28, 2024 19:15:12', '104.28.156.108', 0, 144, 0, 2758.92, -1978.12, 13.551, 0, 0, 1, 0, 4, '21/09/1980', 'Los Santos', 0, '', '', 4605, 250, 0, 99023, 'September 29, 2024 18:38:17', 3, 0, 0, 0, 'None', 6, 1, 1, 0, 0, 0, 0, 0, 0, 0, 4, 258597, 42, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 78, 0, 0, 0, 0, 90, 80, 0, 0, 0, 0, 3, 1),
(84, 32, 'Kordell_Stone', 'Kordell', 'September 28, 2024 19:19:13', '114.10.98.246', 4, 20091, 0, 1942.17, -1611.92, 13.2444, 0, 0, 2, 0, 4, '01/02/2000', 'Los Santos', 0, '', '', 35750, 250, 0, 100694, 'September 29, 2024 22:35:54', 37, 0, 0, 0, 'None', 9, 8, 1, 0, 0, 0, 0, 0, 0, 0, 12, 287513, 62, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(85, 33, 'Qwayshawn_Farrelle', 'Fare', 'September 28, 2024 19:43:47', '140.213.177.125', 0, 144, 0, 2086.22, -1262.23, 23.9921, 0, 0, 1, 0, 0, '16/09/1972', 'Los Santos', 0, '', '', 250, 250, 0, 98236, 'October 2, 2024 12:18:51', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 371015, 75, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(86, 34, 'Jovnazuel_Lotunaz', 'East Coast', 'September 29, 2024 17:04:31', '114.79.47.229', 0, 25, 0, 2251.81, -1260.9, 23.9634, 0, 0, 1, 0, 0, '13/11/1998', 'Los Santos', 0, '', '', -6500, 250, 0, 96060, 'October 6, 2024 12:13:18', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 330070, 85, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(86, 35, 'Vico_Perez', 'East Side Locos', 'September 29, 2024 17:08:16', '115.178.239.4', 0, 48, 0, 2233.92, -1260.88, 23.9312, 0, 0, 1, 0, 0, '13/11/1996', 'Los Santos', 0, '', '', 250, 250, 0, 95572, 'October 6, 2024 19:30:24', 13, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 237660, 63, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 1, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(89, 36, 'Kevin_Navarro', 'Spooks', 'September 29, 2024 17:13:34', '103.124.199.54', 0, 20061, 0, 1954.48, -1975.35, 13.5469, 0, 0, 1, 0, 0, '02/01/1990', 'Los Santos', 0, '', '', 250, 250, 0, 95175, 'October 6, 2024 16:22:47', 6, 0, 0, 0, 'None', 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 360931, 88, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(90, 37, 'Jurel_Muck', 'Jurel', 'September 29, 2024 17:22:42', '180.253.185.244', 0, 66, 0, 2219.52, -1468.28, 24.886, 0, 0, 1, 0, 0, '02/07/2004', 'Los Santos', 0, 'Skip', '\"skip\"', 250, 250, 0, 99910, 'September 29, 2024 17:48:22', 10, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250054, 77, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(98, 38, 'Tyreek_Anderson', 'Movez', 'September 29, 2024 21:00:46', '114.5.217.166', 3, 20091, 0, 2190.02, -1749.07, 13.375, 0, 0, 1, 0, 0, '08/11/1992', 'East Los Santos', 0, '', '', 225, 250, 0, 100936, 'September 29, 2024 21:52:56', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 264098, 61, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(94, 39, 'Rasaun_Hubbard', 'Sauns', 'September 29, 2024 21:15:39', '114.125.92.238', 0, 20038, 0, 2764.13, -1962.16, 13.058, 0, 0, 1, 0, 0, '05/10/1970', 'United State Of America', 0, '', '', 250, 250, 0, 99583, 'September 29, 2024 21:43:21', 15, 0, 0, 0, 'None', 6, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 393102, 60, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(93, 40, 'LeMaun_Cole', 'BeeMurda', 'September 29, 2024 21:44:18', '36.85.219.79', 0, 28, 0, 2278.99, -1329.75, 23.9897, 0, 0, 1, 0, 0, '09/02/1961', 'Los santos', 0, '', '', 250, 250, 0, 100569, 'September 29, 2024 21:53:59', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244108, 50, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(18, 41, 'Bryan_Jefferson', 'Bryan', 'September 29, 2024 21:48:48', '103.147.9.93', 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, '02/02/1960', 'Los santos', 0, '', '', 250, 250, 0, 96045, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(93, 42, 'Leshaun_Cole', 'Maccin', 'September 29, 2024 21:50:31', '36.85.219.79', 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, '09/08/1967', 'Los santos', 0, '', '', 250, 250, 0, 94222, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(100, 43, 'Kai_Wilson', 'Kolio', 'September 29, 2024 22:20:53', '76.219.124.42', 0, 20095, 0, 1152.18, -1233.05, 16.5755, 0, 0, 1, 0, 0, '05/12/1966', 'Los Santos', 0, '', '', 250, 250, 0, 97273, 'October 1, 2024 07:46:02', 24, 0, 0, 0, 'None', 11, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 322664, 80, 0, 8, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(86, 44, 'Javroz_Lozotu', 'Javrozer', 'October 2, 2024 12:08:31', '114.79.47.248', 0, 21, 0, 2493.39, -1670.36, 13.3359, 0, 0, 1, 0, 0, '13/11/1997', 'Los Santos', 0, '', '', 252, 250, 0, 100680, 'October 8, 2024 03:40:58', 11, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 390047, 73, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1),
(105, 45, 'Marco_Vincente', 'Corvez', 'October 6, 2024 12:17:28', '103.171.165.214', 0, 47, 0, 2546.53, -944.937, 82.8258, 0, 0, 1, 0, 0, '2002', 'Mexican', 0, 'was a black mexican', 'a', 251, 250, 0, 95994, 'October 6, 2024 12:22:39', 7, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 206136, 41, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1),
(106, 46, 'Micheal_Moore', 'Capone', 'October 6, 2024 19:30:04', '151.49.49.129', 0, 143, 0, 2240.37, -1417.96, 23.9526, 0, 0, 1, 0, 0, '29/04/1974', 'Los Santos, Jefferson.', 0, '', '', 250, 250, 0, 94855, 'October 6, 2024 19:43:09', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 397579, 66, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(108, 47, 'Jack_Atos', 'test', 'October 8, 2024 00:31:55', '14.216.118.4', 0, 30, 0, 0, 0, 0, 0, 0, 1, 0, 0, '02/02/1960', 'Los santos', 0, '', '', 250, 250, 0, 99195, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(108, 48, 'Jack_Leng', 'asdasd', 'October 8, 2024 00:32:42', '14.216.118.4', 0, 48, 0, 0, 0, 0, 0, 0, 1, 0, 0, '02/02/1960', 'asdasda', 0, 'asdasdas', 'asd', 250, 250, 0, 95061, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `contacts`
--

CREATE TABLE `contacts` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `contactName` varchar(32) NOT NULL DEFAULT 'none',
  `contactID` int(11) NOT NULL DEFAULT 0,
  `contactNumber` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `court`
--

CREATE TABLE `court` (
  `ID` int(11) NOT NULL,
  `ballx` float NOT NULL DEFAULT 0,
  `bally` float NOT NULL DEFAULT 0,
  `ballz` float NOT NULL DEFAULT 0,
  `bluex` float NOT NULL DEFAULT 0,
  `bluey` float NOT NULL DEFAULT 0,
  `bluez` float NOT NULL DEFAULT 0,
  `redx` float NOT NULL DEFAULT 0,
  `redy` float NOT NULL DEFAULT 0,
  `redz` float NOT NULL DEFAULT 0,
  `bluebx` float NOT NULL DEFAULT 0,
  `blueby` float NOT NULL DEFAULT 0,
  `bluebz` float NOT NULL DEFAULT 0,
  `redbx` float NOT NULL DEFAULT 0,
  `redby` float NOT NULL DEFAULT 0,
  `redbz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `court`
--

INSERT INTO `court` (`ID`, `ballx`, `bally`, `ballz`, `bluex`, `bluey`, `bluez`, `redx`, `redy`, `redz`, `bluebx`, `blueby`, `bluebz`, `redbx`, `redby`, `redbz`) VALUES
(3, 2316.91, -1527.57, 24.544, 2317, -1539.97, 24.344, 2317.02, -1515.59, 24.344, 2317.01, -1541.1, 27.364, 2316.87, -1514.77, 27.394),
(4, 2290.52, -1528.25, 26.075, 2290.6, -1540.91, 26.075, 2290.61, -1514.93, 26.075, 2290.7, -1541.11, 28.945, 2290.49, -1514.8, 28.875),
(5, 2782.18, -2019.61, 12.755, 2794.68, -2019.58, 12.755, 2769.08, -2019.6, 12.755, 2794.99, -2019.52, 15.445, 2768.69, -2019.7, 15.425),
(6, 2045.32, -1690.38, 12.755, 2045.58, -1687.72, 12.755, 0, 0, 0, 2045.47, -1687.73, 15.677, 0, 0, 0),
(7, 2528.95, -1667.76, 15.1689, 0, 0, 0, 0, 0, 0, 2533.4, -1667.53, 17.0789, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `criminal_record`
--

CREATE TABLE `criminal_record` (
  `idx` int(11) NOT NULL,
  `player_name` varchar(32) NOT NULL DEFAULT 'None',
  `charge_reason` varchar(128) NOT NULL DEFAULT 'None',
  `add_date` varchar(90) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `criminal_record`
--

INSERT INTO `criminal_record` (`idx`, `player_name`, `charge_reason`, `add_date`) VALUES
(22, 'Radeetz', 'lorem ipsum', 'July 10, 2024 20:51:57'),
(23, 'Blixkyy', 'Grand Theft Auto', 'July 11, 2024 11:54:27');

-- --------------------------------------------------------

--
-- Table structure for table `dropped`
--

CREATE TABLE `dropped` (
  `ID` int(12) NOT NULL,
  `itemName` varchar(32) DEFAULT NULL,
  `itemModel` int(12) DEFAULT 0,
  `itemX` float DEFAULT 0,
  `itemY` float DEFAULT 0,
  `itemZ` float DEFAULT 0,
  `itemRX` float DEFAULT 0,
  `itemRY` float DEFAULT 0,
  `itemRZ` float DEFAULT 0,
  `itemInt` int(12) DEFAULT 0,
  `itemWorld` int(12) DEFAULT 0,
  `itemQuantity` int(12) DEFAULT 0,
  `itemAmount` int(12) DEFAULT 0,
  `itemType` int(12) DEFAULT 0,
  `itemPlayer` varchar(24) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `entrance`
--

CREATE TABLE `entrance` (
  `ID` int(11) NOT NULL,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `intx` float NOT NULL DEFAULT 0,
  `inty` float NOT NULL DEFAULT 0,
  `intz` float NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `icon` int(11) NOT NULL DEFAULT 0,
  `garage` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `entrance`
--

INSERT INTO `entrance` (`ID`, `posx`, `posy`, `posz`, `intx`, `inty`, `intz`, `interior`, `world`, `icon`, `garage`) VALUES
(1, 1554.81, -1675.61, 16.1953, 246.771, 62.628, 1003.64, 6, 24518, 30, 0);

-- --------------------------------------------------------

--
-- Table structure for table `factions`
--

CREATE TABLE `factions` (
  `DBID` int(11) NOT NULL,
  `FactionName` varchar(90) NOT NULL DEFAULT 'None',
  `FactionAbbrev` varchar(30) NOT NULL DEFAULT 'None',
  `FactionSpawnX` float NOT NULL DEFAULT 0,
  `FactionSpawnY` float NOT NULL DEFAULT 0,
  `FactionSpawnZ` float NOT NULL DEFAULT 0,
  `FactionInterior` int(11) NOT NULL DEFAULT 0,
  `FactionWorld` int(11) NOT NULL DEFAULT 0,
  `FactionJoinRank` int(11) NOT NULL DEFAULT 0,
  `FactionAlterRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatRank` int(11) NOT NULL DEFAULT 0,
  `FactionTowRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatColor` int(11) NOT NULL DEFAULT 0,
  `FactionType` tinyint(4) NOT NULL DEFAULT 0,
  `FactionInteriorId` int(11) NOT NULL DEFAULT 0,
  `FactionInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `FactionTurfTokens` int(11) NOT NULL DEFAULT 0,
  `FactionDrugs` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `factions`
--

INSERT INTO `factions` (`DBID`, `FactionName`, `FactionAbbrev`, `FactionSpawnX`, `FactionSpawnY`, `FactionSpawnZ`, `FactionInterior`, `FactionWorld`, `FactionJoinRank`, `FactionAlterRank`, `FactionChatRank`, `FactionTowRank`, `FactionChatColor`, `FactionType`, `FactionInteriorId`, `FactionInteriorWorld`, `FactionTurfTokens`, `FactionDrugs`) VALUES
(4, 'Los Santos Police Departement', 'LSPD', 1546.98, -1670.34, 13.567, 0, 0, 0, 0, 0, 0, -1920073729, 2, 6, 0, 1, 15),
(5, 'Los santos Medical Departement', 'LSMD', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 15);

-- --------------------------------------------------------

--
-- Table structure for table `faction_ranks`
--

CREATE TABLE `faction_ranks` (
  `factionid` int(11) NOT NULL,
  `FactionRank1` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank2` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank3` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank4` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank5` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank6` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank7` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank8` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank9` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank10` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank11` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank12` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank13` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank14` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank15` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank16` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank17` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank18` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank19` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank20` varchar(60) NOT NULL DEFAULT 'NotSet'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `ID` int(12) DEFAULT 0,
  `invID` int(12) NOT NULL,
  `invItem` varchar(32) DEFAULT NULL,
  `invModel` int(12) DEFAULT 0,
  `invQuantity` int(12) DEFAULT 0,
  `invType` int(12) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`ID`, `invID`, `invItem`, `invModel`, `invQuantity`, `invType`) VALUES
(1, 585, 'Raw Meat', 19582, 1, 0),
(28, 588, 'Nail Bat', -2202, 1, 0),
(28, 589, 'Glock 17', -2204, 1, 0),
(32, 593, 'Colt 45', -2205, 1, 0),
(1, 595, 'Spraycan', 365, 2, 0),
(32, 599, 'Mac 12', -2208, 60, 0),
(32, 601, 'Spraycan', 365, 3, 0),
(28, 603, 'Weapon Uzi', -2207, 50, 0),
(32, 604, 'Weapon Uzi', -2207, 50, 0),
(32, 605, 'Rubber Ammo', 2040, 50, 0),
(28, 606, 'Glock P80', -2206, 1, 0),
(32, 607, 'Glock 17', -2204, 50, 0),
(32, 608, 'Glock P80', -2206, 50, 0),
(32, 610, '9x19mm', 2040, 79, 0),
(43, 612, 'Cocaine', -2502, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `kick_logs`
--

CREATE TABLE `kick_logs` (
  `id` int(11) NOT NULL,
  `KickedDBID` int(11) NOT NULL,
  `KickedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `KickedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `logs`
--

CREATE TABLE `logs` (
  `type` varchar(512) NOT NULL DEFAULT 'none',
  `name` varchar(512) NOT NULL DEFAULT 'none',
  `result` varchar(512) NOT NULL DEFAULT 'none',
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `masters`
--

CREATE TABLE `masters` (
  `acc_dbid` int(11) NOT NULL,
  `acc_name` varchar(32) NOT NULL DEFAULT 'None',
  `acc_pass` varchar(128) NOT NULL DEFAULT 'None',
  `secret_word` int(11) NOT NULL DEFAULT 0,
  `forum_name` varchar(60) NOT NULL DEFAULT 'Null',
  `register_date` varchar(90) NOT NULL DEFAULT 'None',
  `register_ip` varchar(60) NOT NULL DEFAULT 'None',
  `active_ip` varchar(60) NOT NULL DEFAULT 'None',
  `verified` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `masters`
--

INSERT INTO `masters` (`acc_dbid`, `acc_name`, `acc_pass`, `secret_word`, `forum_name`, `register_date`, `register_ip`, `active_ip`, `verified`) VALUES
(18, 'Radeetz', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 98765, 'Radeetz', 'February 12, 2024 19:46:10', '127.0.0.1', '127.0.0.1', 1),
(60, 'Blixkyyy', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 4865, 'None', 'May 2, 2024 13:04:40', '127.0.0.1', '127.0.0.1', 1),
(62, 'Tupacc', 'f9376428edb0e1caaa01bcf9c1bd91a8d9448fb0', 2241, 'Tupacc', 'July 19, 2024 05:24:08', '114.10.21.114', '', 1),
(63, 'MarV', '', 8714, 'Null', '', '', '', 0),
(65, 'Sweet', '8f4f9f2dcbaf9bd8ee9e4d1a2cb971a04084157b', 9702, 'Sweet', 'July 20, 2024 20:30:16', '180.242.152.175', '180.242.152.175', 1),
(67, 'secondx', '', 3514, 'Null', '', '', '', 0),
(68, 'Omar', 'eaa76c03f382961040986ee4d05a340191874ce3', 2406, 'Omar', 'July 20, 2024 14:27:10', '103.255.157.178', '103.255.157.178', 1),
(69, 'LHam', '', 9194, 'Null', '', '', '', 0),
(70, 'kiyo', '', 7876, 'Null', '', '', '', 0),
(71, 'Lakey', '55d23a2e19ab316570ba3e0d5074e44432bd423d', 6216, 'Lakey', 'July 20, 2024 11:45:02', '104.28.157.116', '104.28.157.116', 1),
(73, 'BigSmoke', 'd2af5ffecd269d6aa5eecb9438248fc28fd6b830', 6829, 'BigSmoke', 'July 20, 2024 10:30:24', '182.5.8.196', '182.5.8.196', 1),
(74, 'deyvon', '772b7554d883ca159e5f8f3cade4a654701e8d74', 6976, 'deyvon', 'July 20, 2024 10:58:35', '202.80.213.122', '202.80.213.122', 1),
(75, 'David', 'fc54f6a0dfdb5460b82ee93387411ec85be9f779', 7857, 'David', 'July 20, 2024 15:05:19', '114.5.248.243', '114.5.248.243', 1),
(76, 'Grote_Vanderlinde', 'e55e1e7ce85ec1a6339c596539dfa5c3011e6300', 8642, 'Grote_Vanderlinde', 'July 20, 2024 17:43:46', '125.163.226.218', '125.163.226.218', 1),
(77, 'CrizzRocc', 'None', 3003, 'Null', 'None', 'None', 'None', 0),
(78, 'Breeze', 'None', 6002, 'Null', 'None', 'None', 'None', 0),
(79, 'Craig', 'None', 8903, 'Null', 'None', 'None', 'None', 0),
(80, 'AkRow', 'e4a86ea81c680b5a1b9a0e9635ba6b49c2971bc8', 0, 'AkRow', 'September 28, 2024 18:58:31', '112.215.238.250', '140.213.15.3', 0),
(81, 'Daffies', '79e35140f109bf6218d228336c249674d5e9f638', 0, 'Daffies', 'September 28, 2024 19:08:42', '104.28.156.108', '', 0),
(82, 'HexySlimeDreams', '97b1726be6a1fb0f5645e625460eb0b3bb50a90a', 0, 'HexySlimeDreams', 'September 28, 2024 19:10:24', '114.10.98.246', 'None', 0),
(83, 'Kordell_Stone', '97b1726be6a1fb0f5645e625460eb0b3bb50a90a', 0, 'Kordell_Stone', 'September 28, 2024 19:15:23', '114.10.98.246', 'None', 0),
(84, 'Rocksout', '2d3d1937610668e9df1e73ce4268ba0efb206975', 0, 'Rocksout', 'September 28, 2024 19:17:38', '114.10.98.246', '114.10.99.5', 0),
(85, 'float', '1a578c45d7bb3479bcda4981ed2add9532cae0c2', 0, 'float', 'September 28, 2024 19:31:26', '140.213.177.125', '103.51.205.30', 0),
(86, 'arilflexose', '9661e57d76fce048ad1f1231df60a486a73f0e44', 0, 'arilflexose', 'September 28, 2024 19:40:52', '114.79.32.145', '114.79.47.248', 0),
(87, 'Destin_Perry', '79e35140f109bf6218d228336c249674d5e9f638', 0, 'Destin_Perry', 'September 29, 2024 16:06:28', '104.28.159.67', 'None', 0),
(88, 'Hobigtasa', 'fbe4c7c769befa0b94de3d6a9baf960df0eab6df', 0, 'Hobigtasa', 'September 29, 2024 17:04:51', '180.242.214.108', '180.242.214.191', 0),
(89, 'asmyvngk', '3ca46fea48968c50bf78e820fe7a6de484797805', 0, 'asmyvngk', 'September 29, 2024 17:12:01', '103.124.199.54', '103.124.199.54', 0),
(90, 'Droppes', '7c44cdc6bd312b2d77671313df8d558b0e6d6dce', 0, 'Droppes', 'September 29, 2024 17:12:51', '180.253.185.244', '180.253.185.244', 0),
(91, 'nikeeee', '59ec641fc80bb8823744283f7bb93ce9949286bb', 0, 'nikeeee', 'September 29, 2024 18:08:59', '151.0.51.162', '151.0.51.162', 0),
(92, 'ese_nikitosio', '59ec641fc80bb8823744283f7bb93ce9949286bb', 0, 'ese_nikitosio', 'September 29, 2024 18:17:33', '151.0.51.162', '151.0.51.162', 0),
(93, 'cranky', '9cf7817906a081fea133b6791cafb653f531380b', 0, 'cranky', 'September 29, 2024 18:36:26', '36.85.219.79', '36.85.219.79', 0),
(94, 'Jepen', '3444c02261aafa5c6000fccac0692c35c690d7c0', 0, 'Jepen', 'September 29, 2024 18:40:12', '36.68.52.212', '114.125.92.238', 0),
(95, 'Yukimaru', '42e1e77e7ae9939a7b49ca0e5bf3460f25162ed0', 0, 'Yukimaru', 'September 29, 2024 18:41:30', '196.119.110.143', '196.119.110.143', 0),
(96, 'Rasaun_Hubbard', '3444c02261aafa5c6000fccac0692c35c690d7c0', 0, 'Rasaun_Hubbard', 'September 29, 2024 18:42:28', '36.68.52.212', 'None', 0),
(97, 'Martin_Chesterfield', '5e591ed84c772939812abdc81244032252cdb2d5', 0, 'Martin_Chesterfield', 'September 29, 2024 18:46:19', '154.107.172.212', 'None', 0),
(98, 'Borisu', 'fc54f6a0dfdb5460b82ee93387411ec85be9f779', 0, 'Borisu', 'September 29, 2024 20:56:31', '103.175.229.105', '114.5.217.166', 0),
(99, 'Akeem', '8789a2b7d869bda52a19ae74b127603e52f99f4f', 0, 'Akeem', 'September 29, 2024 21:21:22', '90.64.114.144', '90.64.114.144', 0),
(100, '[TDB]Kolio', '1b0c2fdcc0070c002cd691b839505525dcfdcac1', 0, '[TDB]Kolio', 'September 29, 2024 22:18:36', '76.219.124.42', '76.219.124.42', 0),
(101, 'Bazir', 'afe56c80289f0de5eba8ec64dba3bf3b1713d7e7', 0, 'Bazir', 'September 30, 2024 17:07:14', '36.74.43.76', '36.74.43.76', 0),
(102, 'Kobi', '7590e9fb1df30759012303e39dd23c1d45c00d05', 0, 'Kobi', 'October 5, 2024 13:48:45', '103.18.34.177', '103.18.34.177', 0),
(103, 'Marco', '695aa459a3efdbddb3a0229363de526cf2ad4a33', 0, 'Marco', 'October 5, 2024 22:21:01', '103.171.165.214', 'None', 0),
(104, 'Radeetzz', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 0, 'Radeetzz', 'October 6, 2024 10:55:36', '103.147.9.182', 'None', 0),
(105, 'MarrMissHer', '695aa459a3efdbddb3a0229363de526cf2ad4a33', 0, 'MarrMissHer', 'October 6, 2024 12:12:18', '103.171.165.214', '103.171.165.214', 0),
(106, '[RHB]Dwrld', 'f961c8be74525e2f942c024695b5890dfa04eab3', 0, '[RHB]Dwrld', 'October 6, 2024 19:23:32', '151.49.49.129', '103.124.199.54', 0),
(107, 'Dwrld', 'f961c8be74525e2f942c024695b5890dfa04eab3', 0, 'Dwrld', 'October 6, 2024 19:31:08', '151.49.49.129', '151.49.49.129', 0),
(108, 'siwode', '7c4a8d09ca3762af61e59520943dc26494f8941b', 0, 'siwode', 'October 8, 2024 00:30:41', '14.216.118.4', 'None', 0),
(109, 'Verbabbter', '16a28ed822d7a312b5644c2c967cf2bf30a07348', 0, 'Verbabbter', 'October 8, 2024 03:37:24', '178.25.35.70', '178.25.35.70', 0);

-- --------------------------------------------------------

--
-- Table structure for table `properties`
--

CREATE TABLE `properties` (
  `PropertyDBID` int(11) NOT NULL,
  `PropertyOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `PropertyType` int(11) NOT NULL,
  `PropertyFaction` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceX` float NOT NULL DEFAULT 0,
  `PropertyEntranceY` float NOT NULL DEFAULT 0,
  `PropertyEntranceZ` float NOT NULL DEFAULT 0,
  `PropertyEntranceInterior` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorX` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorY` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorZ` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyMarketPrice` int(11) NOT NULL DEFAULT 1000,
  `PropertyLevel` int(11) NOT NULL DEFAULT 1,
  `PropertyLocked` tinyint(1) NOT NULL DEFAULT 0,
  `PropertyCashbox` int(11) NOT NULL DEFAULT 0,
  `PropertyAddress` varchar(128) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `properties`
--

INSERT INTO `properties` (`PropertyDBID`, `PropertyOwnerDBID`, `PropertyType`, `PropertyFaction`, `PropertyEntranceX`, `PropertyEntranceY`, `PropertyEntranceZ`, `PropertyEntranceInterior`, `PropertyEntranceWorld`, `PropertyInteriorX`, `PropertyInteriorY`, `PropertyInteriorZ`, `PropertyInteriorIntID`, `PropertyInteriorWorld`, `PropertyMarketPrice`, `PropertyLevel`, `PropertyLocked`, `PropertyCashbox`, `PropertyAddress`) VALUES
(25, 0, 1, 0, 1962.43, -1721.79, 14.8919, 0, 0, 227, 1240, 1082, 2, 9164, 80000, 0, 0, 0, '1th Martin Luther King Drive'),
(26, 0, 1, 0, 1960.17, -1705.24, 14.3763, 0, 0, 227, 1240, 1082, 2, 33588, 80000, 0, 0, 0, '2th Martin Luther King Drive'),
(27, 0, 1, 0, 1959.17, -1688.68, 14.1263, 0, 0, 227, 1240, 1082, 2, 19655, 80000, 0, 0, 0, '3th Martin Luther King Drive');

-- --------------------------------------------------------

--
-- Table structure for table `relations`
--

CREATE TABLE `relations` (
  `ID` int(11) NOT NULL,
  `RelationsID` int(11) NOT NULL DEFAULT 0,
  `BusinessID` int(11) NOT NULL DEFAULT 0,
  `RelationsPoints` int(11) NOT NULL DEFAULT 0,
  `RelationsBusinessName` varchar(90) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `relations`
--

INSERT INTO `relations` (`ID`, `RelationsID`, `BusinessID`, `RelationsPoints`, `RelationsBusinessName`) VALUES
(1, 9, 47, 100, 'Pawnstore Plaza'),
(2, 1, 47, 0, 'Pawnstore Plaza'),
(3, 34, 64, 100, '');

-- --------------------------------------------------------

--
-- Table structure for table `server_data`
--

CREATE TABLE `server_data` (
  `id` int(12) NOT NULL,
  `products` int(11) NOT NULL DEFAULT 0,
  `crates` int(11) NOT NULL DEFAULT 0,
  `clothes` int(11) NOT NULL DEFAULT 0,
  `tools` int(11) NOT NULL DEFAULT 0,
  `foods` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `server_data`
--

INSERT INTO `server_data` (`id`, `products`, `crates`, `clothes`, `tools`, `foods`) VALUES
(1, 0, 16, -1, -5, -7);

-- --------------------------------------------------------

--
-- Table structure for table `spawnables`
--

CREATE TABLE `spawnables` (
  `spawnablesID` int(11) NOT NULL,
  `spawnablesX` float NOT NULL DEFAULT 0,
  `spawnablesY` float NOT NULL DEFAULT 0,
  `spawnablesZ` float NOT NULL DEFAULT 0,
  `spawnablesRX` float NOT NULL DEFAULT 0,
  `spawnablesRY` float NOT NULL DEFAULT 0,
  `spawnablesRZ` float NOT NULL DEFAULT 0,
  `spawnablesInterior` int(11) NOT NULL DEFAULT 0,
  `spawnablesWorld` int(11) NOT NULL DEFAULT 0,
  `spawnablesObjectID` int(11) NOT NULL DEFAULT 0,
  `spawnablesType` int(11) NOT NULL DEFAULT 0,
  `spawnablesAmount` int(11) NOT NULL DEFAULT 0,
  `spawnablesOwner` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `spawnables`
--

INSERT INTO `spawnables` (`spawnablesID`, `spawnablesX`, `spawnablesY`, `spawnablesZ`, `spawnablesRX`, `spawnablesRY`, `spawnablesRZ`, `spawnablesInterior`, `spawnablesWorld`, `spawnablesObjectID`, `spawnablesType`, `spawnablesAmount`, `spawnablesOwner`) VALUES
(6, 2230.06, -1430.63, 27.6016, 0, 0, 0, 0, 0, 19585, 1, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `spray_tags`
--

CREATE TABLE `spray_tags` (
  `id` int(11) UNSIGNED NOT NULL,
  `owner` int(11) NOT NULL DEFAULT 0,
  `vehicle` int(11) NOT NULL DEFAULT -1,
  `text` varchar(128) NOT NULL DEFAULT 'Exemplo',
  `models` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `font` varchar(128) NOT NULL DEFAULT 'Arial',
  `fontsize` int(11) NOT NULL DEFAULT 24,
  `bold` int(11) NOT NULL DEFAULT 0,
  `color` int(11) NOT NULL DEFAULT 0,
  `posx` varchar(32) DEFAULT '0.0',
  `posy` varchar(32) DEFAULT '0.0',
  `posz` varchar(32) DEFAULT '0.0',
  `posrx` varchar(32) DEFAULT '0.0',
  `posry` varchar(32) DEFAULT '0.0',
  `posrz` varchar(32) DEFAULT NULL,
  `vw` int(11) DEFAULT 0,
  `interior` int(11) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `spray_tags`
--

INSERT INTO `spray_tags` (`id`, `owner`, `vehicle`, `text`, `models`, `type`, `font`, `fontsize`, `bold`, `color`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `vw`, `interior`) VALUES
(257, 1, -1, 'nta Maria Beach', 18659, 1, 'Arial', 24, 0, -5502521, '355.1947', '-2058.1713', '8.8059', '0.0000', '0.0000', '0.0000', 0, 0),
(258, 32, -1, '', 18659, 1, '', 24, 0, 0, '2484.4277', '-1691.9122', '13.6576', '0.0000', '0.0000', '-4.3999', 0, 0),
(259, 32, -1, '', 18666, 1, '', 24, 0, 0, '1952.2263', '-1586.3728', '14.2194', '0.0000', '0.0000', '45.3999', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `toys`
--

CREATE TABLE `toys` (
  `Id` int(10) NOT NULL,
  `Owner` int(11) NOT NULL DEFAULT 0,
  `Slot0_Model` int(8) NOT NULL DEFAULT 0,
  `Slot0_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot0_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_Model` int(8) NOT NULL DEFAULT 0,
  `Slot1_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot1_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_Model` int(8) NOT NULL DEFAULT 0,
  `Slot2_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot2_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_Model` int(8) NOT NULL DEFAULT 0,
  `Slot3_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot3_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_Model` int(8) NOT NULL DEFAULT 0,
  `Slot4_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot4_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_Model` int(8) NOT NULL DEFAULT 0,
  `Slot5_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot5_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot1_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot2_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot3_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot4_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot0_Type` int(11) NOT NULL DEFAULT 0,
  `Slot1_Type` int(11) NOT NULL DEFAULT 0,
  `Slot2_Type` int(11) NOT NULL DEFAULT 0,
  `Slot3_Type` int(11) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `toys`
--

INSERT INTO `toys` (`Id`, `Owner`, `Slot0_Model`, `Slot0_Bone`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot0_XScale`, `Slot0_YScale`, `Slot0_ZScale`, `Slot1_Model`, `Slot1_Bone`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot1_XScale`, `Slot1_YScale`, `Slot1_ZScale`, `Slot2_Model`, `Slot2_Bone`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot2_XScale`, `Slot2_YScale`, `Slot2_ZScale`, `Slot3_Model`, `Slot3_Bone`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot3_XScale`, `Slot3_YScale`, `Slot3_ZScale`, `Slot4_Model`, `Slot4_Bone`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot4_XScale`, `Slot4_YScale`, `Slot4_ZScale`, `Slot5_Model`, `Slot5_Bone`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`, `Slot5_XScale`, `Slot5_YScale`, `Slot5_ZScale`, `Slot0_Toggle`, `Slot1_Toggle`, `Slot2_Toggle`, `Slot3_Toggle`, `Slot4_Toggle`, `Slot0_Type`, `Slot1_Type`, `Slot2_Type`, `Slot3_Type`) VALUES
(18, 11, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 9, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 10, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(15, 1, 0, 1, 0.330, 0.216, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 1, 0.264, 0.081, 0.000, -103.500, 90.300, -177.700, 1.000, 1.000, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(19, 12, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 13, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(21, 14, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(22, 15, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(23, 16, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(24, 17, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25, 18, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(26, 19, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27, 20, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(28, 21, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(29, 22, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30, 23, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(31, 24, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(32, 26, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(33, 28, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(34, 31, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(35, 32, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(36, 33, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37, 29, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(38, 34, 18640, 2, 0.067, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(39, 35, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(40, 36, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(41, 37, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(42, 38, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43, 39, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(44, 40, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(45, 43, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(46, 44, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(47, 45, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(48, 46, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `trashcan`
--

CREATE TABLE `trashcan` (
  `id` int(11) NOT NULL,
  `value` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL,
  `posy` float NOT NULL,
  `posz` float NOT NULL,
  `posrx` float NOT NULL,
  `posry` float NOT NULL,
  `posrz` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `trashcan`
--

INSERT INTO `trashcan` (`id`, `value`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`) VALUES
(4, 0, 2018.16, -1741.9, 12.9669, 0, 0, 0),
(5, 0, 2044.91, -1701.68, 13.0412, 0, 0, 0),
(6, 0, 2056.27, -1780.42, 13.0171, 0, 0, 0),
(7, 0, 2093.16, -1789.03, 12.8855, 0, 0, 0),
(8, 0, 2108.35, -1885.34, 13.0189, 0, 0, 0),
(9, 0, 2228.08, -1883.67, 13.0228, 0, 0, 0),
(10, 0, 1213.76, -1121.47, 25.0156, 0, 0, 0),
(11, 0, 1518.72, -1604.78, 13.036, 0, 0, 0),
(12, 0, 1565.4, -1580.83, 13.0186, 0, 0, 0),
(13, 0, 1883.71, -1606.73, 13.0145, 0, 0, 0),
(14, 0, 2045.82, -1640.53, 13.0216, 0, 0, 0),
(15, 0, 2225.31, -1409.77, 23.4735, 0, 0, 0),
(16, 0, 2101.34, -1263.49, 23.4618, 0, 0, 0),
(17, 0, 2497.86, -1514.6, 23.459, 0, 0, 0),
(18, 0, 2483, -1717.93, 13.0188, 0, 0, 0),
(19, 0, 2325.91, -1758.57, 13.0027, 0, 0, 0),
(20, 0, 1892.64, -2096.25, 12.9476, 0, 0, 0),
(21, 0, 1929.67, -2028.59, 13.018, 0, 0, 0),
(22, 0, 1627.39, -1862.66, 13.0099, 0, 0, 0),
(23, 0, 1459.77, -1862.26, 13.0174, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `turfs`
--

CREATE TABLE `turfs` (
  `id` int(11) NOT NULL,
  `name` varchar(32) DEFAULT NULL,
  `capturedby` varchar(24) DEFAULT 'No-one',
  `capturedgang` tinyint(2) DEFAULT -1,
  `type` tinyint(2) DEFAULT 0,
  `time` tinyint(2) DEFAULT 12,
  `min_x` float DEFAULT 0,
  `min_y` float DEFAULT 0,
  `max_x` float DEFAULT 0,
  `max_y` float DEFAULT 0,
  `height` float DEFAULT 0,
  `gsf` int(11) DEFAULT 0,
  `sbf` int(11) DEFAULT 0,
  `tdf` int(11) DEFAULT 0,
  `ktb` int(11) DEFAULT 0,
  `rhb` int(11) DEFAULT 0,
  `fyb` int(11) DEFAULT 0,
  `tdb` int(11) DEFAULT 0,
  `lsv` int(11) DEFAULT 0,
  `vla` int(11) DEFAULT 0,
  `point` int(11) DEFAULT 2000,
  `drugsx` float DEFAULT 0,
  `drugsy` float DEFAULT 0,
  `drugsz` float DEFAULT 0,
  `drugsa` float DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `turfs`
--

INSERT INTO `turfs` (`id`, `name`, `capturedby`, `capturedgang`, `type`, `time`, `min_x`, `min_y`, `max_x`, `max_y`, `height`, `gsf`, `sbf`, `tdf`, `ktb`, `rhb`, `fyb`, `tdb`, `lsv`, `vla`, `point`, `drugsx`, `drugsy`, `drugsz`, `drugsa`) VALUES
(0, 'none', 'No-one', 6, 1, 12, 2722, -1981.5, 2822, -1881.5, 0, 0, 6, 0, 0, 0, 0, 0, 13, 0, 2000, 2764.91, -1975.31, 13.347, 0),
(2, 'none', 'No-one', 6, 1, 12, 2722, -2081.5, 2822, -1981.5, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 2000, 2725.03, -1999.7, 13.547, 183.278),
(4, 'none', 'No-one', -1, 0, 12, 2622, -1981.5, 2722, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(6, 'none', 'No-one', 6, 1, 12, 2622, -2081.5, 2722, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(8, 'none', 'No-one', -1, 0, 12, 2522, -2081.5, 2622, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(10, 'none', 'No-one', -1, 0, 12, 2522, -1981.5, 2622, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(12, 'none', 'No-one', -1, 0, 12, 2422, -1981.5, 2522, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(14, 'none', 'No-one', -1, 0, 12, 2422, -2081.5, 2522, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(16, 'none', 'No-one', -1, 0, 12, 2322, -1981.5, 2422, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(18, 'none', 'No-one', -1, 0, 12, 2322, -2081.5, 2422, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(20, 'none', 'No-one', -1, 0, 12, 2222, -1981.5, 2322, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(22, 'none', 'No-one', -1, 0, 12, 2222, -2081.5, 2322, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(24, 'none', 'No-one', -1, 0, 12, 2722, -2181.5, 2822, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(26, 'none', 'No-one', -1, 0, 12, 2622, -2181.5, 2722, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(28, 'none', 'No-one', -1, 0, 12, 2522, -2181.5, 2622, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(30, 'none', 'No-one', -1, 0, 12, 2422, -2181.5, 2522, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(32, 'none', 'No-one', -1, 0, 12, 2322, -2181.5, 2422, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(34, 'none', 'No-one', -1, 0, 12, 2222, -2181.5, 2322, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(36, 'none', 'No-one', -1, 0, 12, 2222, -2281.5, 2322, -2181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(38, 'none', 'No-one', -1, 0, 12, 2122, -2281.5, 2222, -2181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(40, 'none', 'No-one', -1, 0, 12, 2122, -2381.5, 2222, -2281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(42, 'none', 'No-one', -1, 0, 12, 2122, -2181.5, 2222, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(44, 'none', 'No-one', -1, 0, 12, 2122, -2081.5, 2222, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(46, 'none', 'No-one', -1, 0, 12, 2122, -1981.5, 2222, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(48, 'none', 'No-one', -1, 0, 12, 2022, -1981.5, 2122, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(50, 'none', 'No-one', -1, 0, 12, 2022, -2081.5, 2122, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(52, 'none', 'No-one', -1, 0, 12, 2022, -2181.5, 2122, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2337.75, -1751.86, 13.3884, 282.328),
(54, 'none', 'No-one', 8, 1, 12, 1922, -2181.5, 2022, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(56, 'none', 'No-one', 8, 1, 12, 1922, -2081.5, 2022, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(58, 'none', 'No-one', -1, 0, 12, 1922, -1981.5, 2022, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(60, 'none', 'No-one', -1, 0, 12, 1822, -1981.5, 1922, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1829.98, -1913.76, 13.528, 89.898),
(62, 'none', 'No-one', 8, 1, 12, 1822, -2081.5, 1922, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(64, 'none', 'No-one', 8, 1, 12, 1822, -2181.5, 1922, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(66, 'none', 'No-one', 8, 1, 12, 1722, -2181.5, 1822, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(68, 'none', 'No-one', -1, 0, 12, 1722, -2081.5, 1822, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(70, 'none', 'No-one', -1, 0, 12, 1722, -1981.5, 1822, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(72, 'none', 'No-one', -1, 0, 12, 1622, -1981.5, 1722, -1881.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(74, 'none', 'No-one', -1, 0, 12, 1622, -2081.5, 1722, -1981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(76, 'none', 'No-one', -1, 0, 12, 1622, -2181.5, 1722, -2081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(78, 'none', 'No-one', -1, 0, 12, 2622, -1881.5, 2849, -1647.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(80, 'none', 'No-one', -1, 0, 12, 2522, -1881.5, 2622, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(82, 'none', 'No-one', -1, 0, 12, 2422, -1881.5, 2522, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(84, 'none', 'No-one', 3, 1, 12, 2322, -1881.5, 2422, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(86, 'none', 'No-one', 3, 1, 12, 2222, -1881.5, 2322, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(88, 'none', 'No-one', -1, 0, 12, 2122, -1881.5, 2222, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(90, 'none', 'No-one', -1, 0, 12, 2022, -1881.5, 2122, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(92, 'none', 'No-one', -1, 0, 12, 1922, -1881.5, 2022, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1972.57, -1786.41, 13.554, 355.166),
(94, 'none', 'No-one', -1, 0, 12, 1822, -1881.5, 1922, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1855.93, -1880.53, 13.441, 176.629),
(96, 'none', 'No-one', -1, 0, 12, 1722, -1881.5, 1822, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(98, 'none', 'No-one', -1, 0, 12, 1622, -1881.5, 1722, -1781.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(100, 'none', 'No-one', -1, 0, 12, 2522, -1781.5, 2622, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(102, 'none', 'No-one', 3, 1, 12, 2422, -1781.5, 2522, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(104, 'none', 'No-one', 3, 1, 12, 2322, -1781.5, 2422, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(106, 'none', 'No-one', -1, 0, 12, 2222, -1781.5, 2322, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(108, 'none', 'No-one', -1, 0, 12, 2122, -1781.5, 2222, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(110, 'none', 'No-one', -1, 0, 12, 2022, -1781.5, 2122, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2044.76, -1726.7, 13.547, 90.212),
(112, 'none', 'No-one', 9, 1, 12, 1922, -1781.5, 2022, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1948.09, -1732.38, 13.547, 82.442),
(114, 'none', 'No-one', -1, 0, 12, 1822, -1781.5, 1922, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1903.25, -1742.79, 13.547, 172.555),
(116, 'none', 'No-one', -1, 0, 12, 1722, -1781.5, 1822, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(118, 'none', 'No-one', -1, 0, 12, 1622, -1781.5, 1722, -1681.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(120, 'none', 'No-one', -1, 0, 12, 1622, -1681.5, 1722, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(122, 'none', 'No-one', -1, 0, 12, 1722, -1681.5, 1822, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(124, 'none', 'No-one', 9, 1, 12, 1822, -1681.5, 1922, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1892.66, -1622.1, 13.547, 353.663),
(126, 'none', 'No-one', 9, 1, 12, 1922, -1681.5, 2022, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2009.44, -1604.32, 13.547, 177.905),
(128, 'none', 'No-one', -1, 0, 12, 2022, -1681.5, 2122, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2037.28, -1655.69, 13.547, 260.04),
(130, 'none', 'No-one', -1, 0, 12, 2122, -1681.5, 2223, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(132, 'none', 'No-one', -1, 0, 12, 2222, -1681.5, 2322, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(134, 'none', 'No-one', -1, 0, 12, 2322, -1681.5, 2422, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(136, 'none', 'No-one', 3, 1, 12, 2422, -1681.5, 2522, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(138, 'none', 'No-one', -1, 0, 12, 2522, -1681.5, 2622, -1581.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(140, 'none', 'No-one', -1, 0, 12, 2622, -1647.5, 2722, -1547.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(142, 'none', 'No-one', -1, 0, 12, 2722, -1647.5, 2822, -1547.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(144, 'none', 'No-one', -1, 0, 12, 2722, -1547.5, 2822, -1447.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(146, 'none', 'No-one', -1, 0, 12, 2622, -1547.5, 2722, -1447.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(148, 'none', 'No-one', -1, 0, 12, 2622, -1447.5, 2722, -1347.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(150, 'none', 'No-one', -1, 0, 12, 2722, -1447.5, 2822, -1347.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(152, 'none', 'No-one', -1, 0, 12, 2622, -1347.5, 2722, -1247.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(154, 'none', 'No-one', -1, 0, 12, 2722, -1347.5, 2822, -1247.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(156, 'none', 'No-one', -1, 0, 12, 2622, -1247.5, 2722, -1147.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(158, 'none', 'No-one', -1, 0, 12, 2722, -1247.5, 2822, -1147.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(160, 'none', 'No-one', -1, 0, 12, 2622, -1147.5, 2722, -1047.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(162, 'none', 'No-one', -1, 0, 12, 2522, -1181.5, 2622, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(164, 'none', 'No-one', -1, 0, 12, 2422, -1281.5, 2522, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(166, 'none', 'No-one', -1, 0, 12, 2522, -1281.5, 2622, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(168, 'none', 'No-one', -1, 0, 12, 2422, -1381.5, 2522, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(170, 'none', 'No-one', -1, 0, 12, 2522, -1381.5, 2622, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(172, 'none', 'No-one', -1, 0, 12, 2422, -1481.5, 2522, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(174, 'none', 'No-one', 7, 1, 12, 2522, -1481.5, 2622, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(176, 'none', 'No-one', 7, 1, 12, 2422, -1581.5, 2522, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(178, 'none', 'No-one', 7, 1, 12, 2522, -1581.5, 2622, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(180, 'none', 'No-one', -1, 0, 12, 2422, -1181.5, 2522, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(182, 'none', 'No-one', -1, 0, 12, 2322, -1581.5, 2422, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(184, 'none', 'No-one', -1, 0, 12, 2322, -1481.5, 2422, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(186, 'none', 'No-one', -1, 0, 12, 2322, -1381.5, 2422, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(188, 'none', 'No-one', -1, 0, 12, 2322, -1281.5, 2422, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(190, 'none', 'No-one', -1, 0, 12, 2322, -1181.5, 2422, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(192, 'none', 'No-one', -1, 0, 12, 1722, -1581.5, 1822, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(194, 'none', 'No-one', -1, 0, 12, 1822, -1581.5, 1922, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 1920.31, -1538.67, 13.539, 24.539),
(196, 'none', 'No-one', -1, 0, 12, 1922, -1581.5, 2022, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2002.07, -1530.53, 3.594, 332.629),
(198, 'none', 'No-one', -1, 0, 12, 2022, -1581.5, 2122, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 2087, -1564, 13.341, 267.873),
(200, 'none', 'No-one', 5, 1, 12, 2122, -1581.5, 2222, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(202, 'none', 'No-one', -1, 0, 12, 2223, -1581.5, 2323, -1481.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(204, 'none', 'No-one', 5, 1, 12, 2222, -1481.5, 2322, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(206, 'none', 'No-one', -1, 0, 12, 2222, -1381.5, 2322, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(208, 'none', 'No-one', -1, 0, 12, 2222, -1281.5, 2322, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(210, 'none', 'No-one', -1, 0, 12, 2222, -1181.5, 2322, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(212, 'none', 'No-one', 5, 1, 12, 2122, -1481.5, 2222, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(214, 'none', 'No-one', -1, 0, 12, 2122, -1381.5, 2222, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(216, 'none', 'No-one', -1, 0, 12, 2122, -1281.5, 2222, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(218, 'none', 'No-one', -1, 0, 12, 2122, -1181.5, 2222, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(220, 'none', 'No-one', -1, 0, 12, 2022, -1481.5, 2122, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(222, 'none', 'No-one', 4, 1, 12, 2022, -1381.5, 2122, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(224, 'none', 'No-one', 4, 1, 12, 2022, -1281.5, 2122, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(226, 'none', 'No-one', -1, 0, 12, 1922, -1481.5, 2022, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(228, 'none', 'No-one', 4, 1, 12, 1922, -1381.5, 2022, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(230, 'none', 'No-one', -1, 0, 12, 2022, -1181.5, 2122, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(232, 'none', 'No-one', -1, 0, 12, 1922, -1281.5, 2022, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(234, 'none', 'No-one', -1, 0, 12, 1822, -1381.5, 1922, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(236, 'none', 'No-one', -1, 0, 12, 1822, -1481.5, 1922, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(238, 'none', 'No-one', -1, 0, 12, 1722, -1481.5, 1822, -1381.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(240, 'none', 'No-one', -1, 0, 12, 1822, -1281.5, 1922, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(242, 'none', 'No-one', -1, 0, 12, 1922, -1181.5, 2022, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(244, 'none', 'No-one', -1, 0, 12, 1822, -1181.5, 1922, -1081.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(246, 'none', 'No-one', -1, 0, 12, 1722, -1381.5, 1822, -1281.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(248, 'none', 'No-one', -1, 0, 12, 1722, -1281.5, 1822, -1181.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(250, 'none', 'No-one', -1, 0, 12, 1822, -1081.5, 1922, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(251, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(252, 'none', 'No-one', -1, 0, 12, 1922, -1081.5, 2022, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(253, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(254, 'none', 'No-one', -1, 0, 12, 2022, -1081.5, 2122, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(255, 'none', 'No-one', -1, 0, 12, 6.30584e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(256, 'none', 'No-one', -1, 0, 12, 2122, -1081.5, 2222, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(257, 'none', 'No-one', -1, 0, 12, 6.30584e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(258, 'none', 'No-one', -1, 0, 12, 2222, -1081.5, 2322, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(259, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(260, 'none', 'No-one', -1, 0, 12, 2322, -1081.5, 2422, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(261, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(262, 'none', 'No-one', -1, 0, 12, 2422, -1081.5, 2522, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(263, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(264, 'none', 'No-one', -1, 0, 12, 2522, -1081.5, 2622, -981.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(265, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(266, 'none', 'No-one', -1, 0, 12, 2122, -981.5, 2222, -936.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(267, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(268, 'none', 'No-one', -1, 0, 12, 2022, -981.5, 2122, -936.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(269, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(270, 'none', 'No-one', -1, 0, 12, 1976, -981.5, 2022, -936.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(271, 'none', 'No-one', -1, 0, 12, 6.30584e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(272, 'none', 'No-one', -1, 0, 12, 1246, -943.5, 1346, -843.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(273, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(274, 'none', 'No-one', -1, 0, 12, 1146, -943.5, 1246, -843.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(275, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(276, 'none', 'No-one', -1, 0, 12, 1046, -943.5, 1146, -843.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(277, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(278, 'none', 'No-one', -1, 0, 12, 946, -943.5, 1046, -843.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(279, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(280, 'none', 'No-one', -1, 0, 12, 1246, -1043.5, 1346, -943.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(281, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(282, 'none', 'No-one', -1, 0, 12, 1246, -1143.5, 1346, -1043.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(283, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(284, 'none', 'No-one', 10, 1, 12, 1146, -1043.5, 1246, -943.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(285, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(286, 'none', 'No-one', 10, 1, 12, 1146, -1143.5, 1246, -1043.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(287, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(288, 'none', 'No-one', 10, 1, 12, 1046, -1043.5, 1146, -943.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(289, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(290, 'none', 'No-one', -1, 0, 12, 1046, -1143.5, 1146, -1043.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(291, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(292, 'none', 'No-one', -1, 0, 12, 946, -1043.5, 1046, -943.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(293, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(294, 'none', 'No-one', -1, 0, 12, 946, -1143.5, 1046, -1043.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(295, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(296, 'none', 'No-one', -1, 0, 12, 1246, -1243.5, 1346, -1143.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(297, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(298, 'none', 'No-one', 11, 1, 12, 1146, -1243.5, 1246, -1143.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(299, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(300, 'none', 'No-one', 11, 1, 12, 1046, -1243.5, 1146, -1143.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(301, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(302, 'none', 'No-one', -1, 0, 12, 946, -1243.5, 1046, -1143.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(303, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(304, 'none', 'No-one', -1, 0, 12, 946, -1343.5, 1046, -1243.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(305, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(306, 'none', 'No-one', -1, 0, 12, 946, -1443.5, 1046, -1343.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(307, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(308, 'none', 'No-one', -1, 0, 12, 746, -1512.5, 846, -1412.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(309, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(310, 'none', 'No-one', -1, 0, 12, 646, -1512.5, 746, -1412.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(311, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(312, 'none', 'No-one', 11, 1, 12, 1046, -1343.5, 1146, -1243.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(313, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(314, 'none', 'No-one', 11, 1, 12, 1146, -1343.5, 1246, -1243.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(315, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(316, 'none', 'No-one', -1, 0, 12, 1246, -1343.5, 1346, -1243.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(317, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(318, 'none', 'No-one', -1, 0, 12, 1246, -1443.5, 1346, -1343.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(319, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(320, 'none', 'No-one', -1, 0, 12, 1146, -1443.5, 1246, -1343.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(321, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(322, 'none', 'No-one', -1, 0, 12, 1046, -1443.5, 1146, -1343.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(323, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(324, 'none', 'No-one', -1, 0, 12, 846, -1412.5, 946, -1312.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(325, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(326, 'none', 'No-one', -1, 0, 12, 746, -1412.5, 846, -1312.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(327, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(328, 'none', 'No-one', -1, 0, 12, 646, -1412.5, 746, -1312.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(329, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(330, 'none', 'No-one', -1, 0, 12, 846, -1512.5, 946, -1412.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(331, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(332, 'none', 'No-one', -1, 0, 12, 646, -1612.5, 746, -1512.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(333, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(334, 'none', 'No-one', -1, 0, 12, 646, -1712.5, 746, -1612.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(335, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(336, 'none', 'No-one', -1, 0, 12, 946, -1543.5, 1046, -1443.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(337, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(338, 'none', 'No-one', -1, 0, 12, 846, -1612.5, 946, -1512.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(339, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(340, 'none', 'No-one', -1, 0, 12, 746, -1612.5, 846, -1512.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(341, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(342, 'none', 'No-one', -1, 0, 12, 746, -1712.5, 846, -1612.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(343, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(344, 'none', 'No-one', -1, 0, 12, 846, -1712.5, 946, -1612.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(345, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(346, 'none', 'No-one', -1, 0, 12, 946, -1643.5, 1046, -1543.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(347, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(348, 'none', 'No-one', -1, 0, 12, 946, -1786.5, 1046, -1643.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(349, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(350, 'none', 'No-one', -1, 0, 12, 646, -1752.5, 746, -1712.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(351, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(352, 'none', 'No-one', -1, 0, 12, 746, -1759.5, 846, -1712.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(353, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(354, 'none', 'No-one', -1, 0, 12, 846, -1763.5, 946, -1712.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(355, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(356, 'none', 'No-one', -1, 0, 12, 846, -1212.5, 946, -1112.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(357, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(358, 'none', 'No-one', -1, 0, 12, 846, -1112.5, 946, -987.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(359, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(360, 'none', 'No-one', -1, 0, 12, 746, -1212.5, 846, -1112.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(361, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(362, 'none', 'No-one', -1, 0, 12, 846, -1312.5, 946, -1212.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(363, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(364, 'none', 'No-one', -1, 0, 12, 746, -1312.5, 846, -1212.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(365, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(366, 'none', 'No-one', -1, 0, 12, 746, -1112.5, 846, -1054.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(367, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(368, 'none', 'No-one', -1, 0, 12, 147, -1796.5, 247, -1696.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(369, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(370, 'none', 'No-one', -1, 0, 12, 247, -1796.5, 362, -1696.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(371, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(372, 'none', 'No-one', -1, 0, 12, 376, -1795.5, 476, -1695.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(373, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(374, 'none', 'No-one', -1, 0, 12, 476, -1795.5, 576, -1695.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(375, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(376, 'none', 'No-one', -1, 0, 12, 576, -1795.5, 647, -1695.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(377, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(378, 'none', 'No-one', -1, 0, 12, 646, -1808.5, 746, -1752.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(379, 'none', 'No-one', -1, 0, 12, 7.84727e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(380, 'none', 'No-one', -1, 0, 12, 746, -1813.5, 846, -1759.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(381, 'none', 'No-one', -1, 0, 12, 7.56701e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(382, 'none', 'No-one', -1, 0, 12, 846, -1823.5, 946, -1763.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(383, 'none', 'No-one', -1, 0, 12, 8.40779e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(384, 'none', 'No-one', -1, 0, 12, 946, -1842.5, 1046, -1786.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(385, 'none', 'No-one', -1, 0, 12, 7.84727e-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(386, 'none', 'No-one', -1, 0, 12, 946, -1942.5, 1046, -1842.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0),
(387, 'none', 'No-one', -1, 0, 12, 1.4013e-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `turfsglobal`
--

CREATE TABLE `turfsglobal` (
  `Turfwars` int(11) NOT NULL DEFAULT 0,
  `Start` int(11) NOT NULL DEFAULT 0,
  `End` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `turfsglobal`
--

INSERT INTO `turfsglobal` (`Turfwars`, `Start`, `End`) VALUES
(1, 2, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vehicles`
--

CREATE TABLE `vehicles` (
  `VehicleDBID` int(11) NOT NULL,
  `VehicleOwnerDBID` int(11) NOT NULL,
  `VehicleFaction` int(11) NOT NULL DEFAULT 0,
  `VehicleModel` int(11) NOT NULL DEFAULT 0,
  `VehicleColor1` int(11) NOT NULL DEFAULT 0,
  `VehicleColor2` int(11) NOT NULL DEFAULT 0,
  `VehiclePaintjob` int(11) NOT NULL DEFAULT -1,
  `VehicleParkPosX` float NOT NULL DEFAULT 0,
  `VehicleParkPosY` float NOT NULL DEFAULT 0,
  `VehicleParkPosZ` float NOT NULL DEFAULT 0,
  `VehicleParkPosA` float NOT NULL DEFAULT 0,
  `VehicleParkInterior` int(11) NOT NULL DEFAULT 0,
  `VehicleParkWorld` int(11) NOT NULL DEFAULT 0,
  `VehiclePlates` varchar(32) NOT NULL DEFAULT 'None',
  `VehicleLocked` int(11) NOT NULL DEFAULT 0,
  `VehicleImpounded` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleImpoundPosX` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosY` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosZ` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosA` float NOT NULL DEFAULT 0,
  `VehicleSirens` int(11) NOT NULL DEFAULT 0,
  `VehicleFuel` float NOT NULL DEFAULT 100,
  `VehicleLastDrivers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers4` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers4` int(11) NOT NULL DEFAULT 0,
  `VehicleBattery` float NOT NULL DEFAULT 100,
  `VehicleEngine` float NOT NULL DEFAULT 100,
  `VehicleTimesDestroyed` int(11) NOT NULL DEFAULT 0,
  `VehicleXMR` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleAlarmLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleLockLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleImmobLevel` int(11) NOT NULL DEFAULT 1,
  `VehicleHealth` float NOT NULL DEFAULT 1000,
  `VehicleMods0` int(11) NOT NULL DEFAULT 0,
  `VehicleMods1` int(11) NOT NULL DEFAULT 0,
  `VehicleMods2` int(11) NOT NULL DEFAULT 0,
  `VehicleMods3` int(11) NOT NULL DEFAULT 0,
  `VehicleMods4` int(11) NOT NULL DEFAULT 0,
  `VehicleMods5` int(11) NOT NULL DEFAULT 0,
  `VehicleMods6` int(11) NOT NULL DEFAULT 0,
  `VehicleMods7` int(11) NOT NULL DEFAULT 0,
  `VehicleMods8` int(11) NOT NULL DEFAULT 0,
  `VehicleMods9` int(11) NOT NULL DEFAULT 0,
  `VehicleMods10` int(11) NOT NULL DEFAULT 0,
  `VehicleMods11` int(11) NOT NULL DEFAULT 0,
  `VehicleMods12` int(11) NOT NULL DEFAULT 0,
  `VehicleMods13` int(11) NOT NULL DEFAULT 0,
  `VehicleWheels` int(11) NOT NULL DEFAULT 0,
  `VehicleHydraulics` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `vehicles`
--

INSERT INTO `vehicles` (`VehicleDBID`, `VehicleOwnerDBID`, `VehicleFaction`, `VehicleModel`, `VehicleColor1`, `VehicleColor2`, `VehiclePaintjob`, `VehicleParkPosX`, `VehicleParkPosY`, `VehicleParkPosZ`, `VehicleParkPosA`, `VehicleParkInterior`, `VehicleParkWorld`, `VehiclePlates`, `VehicleLocked`, `VehicleImpounded`, `VehicleImpoundPosX`, `VehicleImpoundPosY`, `VehicleImpoundPosZ`, `VehicleImpoundPosA`, `VehicleSirens`, `VehicleFuel`, `VehicleLastDrivers1`, `VehicleLastDrivers2`, `VehicleLastDrivers3`, `VehicleLastDrivers4`, `VehicleLastPassengers1`, `VehicleLastPassengers2`, `VehicleLastPassengers3`, `VehicleLastPassengers4`, `VehicleBattery`, `VehicleEngine`, `VehicleTimesDestroyed`, `VehicleXMR`, `VehicleAlarmLevel`, `VehicleLockLevel`, `VehicleImmobLevel`, `VehicleHealth`, `VehicleMods0`, `VehicleMods1`, `VehicleMods2`, `VehicleMods3`, `VehicleMods4`, `VehicleMods5`, `VehicleMods6`, `VehicleMods7`, `VehicleMods8`, `VehicleMods9`, `VehicleMods10`, `VehicleMods11`, `VehicleMods12`, `VehicleMods13`, `VehicleWheels`, `VehicleHydraulics`) VALUES
(77, 1, 0, 456, 7, 7, -1, 2804.67, -2388.09, 13.8118, 90.2733, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 97, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vstorage`
--

CREATE TABLE `vstorage` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `itemID` int(11) NOT NULL,
  `itemModel` int(11) NOT NULL DEFAULT 0,
  `itemQuantity` int(11) NOT NULL DEFAULT 0,
  `itemName` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT NULL,
  `type` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `vstorage`
--

INSERT INTO `vstorage` (`ID`, `itemID`, `itemModel`, `itemQuantity`, `itemName`, `type`) VALUES
(72, 43, 2912, 2, 'Tools Cargo', 0),
(72, 44, 365, 1, 'Spraycan', 0),
(75, 45, 2912, 2, 'Products Cargo', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `bannedlist`
--
ALTER TABLE `bannedlist`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ban_logs`
--
ALTER TABLE `ban_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `businesses`
--
ALTER TABLE `businesses`
  ADD PRIMARY KEY (`BusinessDBID`);

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`char_dbid`);

--
-- Indexes for table `contacts`
--
ALTER TABLE `contacts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `court`
--
ALTER TABLE `court`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `criminal_record`
--
ALTER TABLE `criminal_record`
  ADD PRIMARY KEY (`idx`);

--
-- Indexes for table `dropped`
--
ALTER TABLE `dropped`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `entrance`
--
ALTER TABLE `entrance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `factions`
--
ALTER TABLE `factions`
  ADD PRIMARY KEY (`DBID`);

--
-- Indexes for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  ADD PRIMARY KEY (`factionid`),
  ADD UNIQUE KEY `factionid` (`factionid`);

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`invID`);

--
-- Indexes for table `kick_logs`
--
ALTER TABLE `kick_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `logs`
--
ALTER TABLE `logs`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `masters`
--
ALTER TABLE `masters`
  ADD PRIMARY KEY (`acc_dbid`);

--
-- Indexes for table `properties`
--
ALTER TABLE `properties`
  ADD PRIMARY KEY (`PropertyDBID`);

--
-- Indexes for table `relations`
--
ALTER TABLE `relations`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `server_data`
--
ALTER TABLE `server_data`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `spawnables`
--
ALTER TABLE `spawnables`
  ADD PRIMARY KEY (`spawnablesID`);

--
-- Indexes for table `spray_tags`
--
ALTER TABLE `spray_tags`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `toys`
--
ALTER TABLE `toys`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `id` (`Owner`);

--
-- Indexes for table `trashcan`
--
ALTER TABLE `trashcan`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `turfs`
--
ALTER TABLE `turfs`
  ADD UNIQUE KEY `id` (`id`);

--
-- Indexes for table `turfsglobal`
--
ALTER TABLE `turfsglobal`
  ADD PRIMARY KEY (`Turfwars`);

--
-- Indexes for table `vehicles`
--
ALTER TABLE `vehicles`
  ADD PRIMARY KEY (`VehicleDBID`);

--
-- Indexes for table `vstorage`
--
ALTER TABLE `vstorage`
  ADD PRIMARY KEY (`itemID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `bannedlist`
--
ALTER TABLE `bannedlist`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `ban_logs`
--
ALTER TABLE `ban_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `businesses`
--
ALTER TABLE `businesses`
  MODIFY `BusinessDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=72;

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `char_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=49;

--
-- AUTO_INCREMENT for table `court`
--
ALTER TABLE `court`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `criminal_record`
--
ALTER TABLE `criminal_record`
  MODIFY `idx` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `dropped`
--
ALTER TABLE `dropped`
  MODIFY `ID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=165;

--
-- AUTO_INCREMENT for table `entrance`
--
ALTER TABLE `entrance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `factions`
--
ALTER TABLE `factions`
  MODIFY `DBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  MODIFY `factionid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `inventory`
--
ALTER TABLE `inventory`
  MODIFY `invID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=634;

--
-- AUTO_INCREMENT for table `kick_logs`
--
ALTER TABLE `kick_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `masters`
--
ALTER TABLE `masters`
  MODIFY `acc_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=110;

--
-- AUTO_INCREMENT for table `properties`
--
ALTER TABLE `properties`
  MODIFY `PropertyDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;

--
-- AUTO_INCREMENT for table `relations`
--
ALTER TABLE `relations`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `server_data`
--
ALTER TABLE `server_data`
  MODIFY `id` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `spawnables`
--
ALTER TABLE `spawnables`
  MODIFY `spawnablesID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `spray_tags`
--
ALTER TABLE `spray_tags`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=260;

--
-- AUTO_INCREMENT for table `toys`
--
ALTER TABLE `toys`
  MODIFY `Id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=49;

--
-- AUTO_INCREMENT for table `trashcan`
--
ALTER TABLE `trashcan`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `vehicles`
--
ALTER TABLE `vehicles`
  MODIFY `VehicleDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=78;

--
-- AUTO_INCREMENT for table `vstorage`
--
ALTER TABLE `vstorage`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=47;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
